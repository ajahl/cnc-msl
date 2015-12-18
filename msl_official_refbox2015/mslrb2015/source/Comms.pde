

public static void send_to_basestation(String c){
  //println("Command "+c+" :"+Description.get(c+""));
  BaseStationServer.write(c);
  
  if(!c.equals("" + COMM_WORLD_STATE))
  {
    Log.logactions(c);
    mslRemote.setLastCommand(c);      // Update MSL remote module with last command sent to basestations
  }
}

public static void event_message_v2(ButtonsEnum btn, boolean on)
{
  String cmd = buttonFromEnum(btn).cmd;
  String msg = buttonFromEnum(btn).msg;
  if(!on)
  {
    cmd = buttonFromEnum(btn).cmd_off;
    msg = buttonFromEnum(btn).msg_off;
  }
  
  Team t = null;
  if(btn.isCyan()) t = teamA;
  if(btn.isMagenta()) t = teamB;
  
  String teamName = (t != null) ? t.longName : "";
  
  if(cmd != null && msg != null)
  {
    send_event_v2(cmd, msg, t);
  }
}

public static void send_event_v2(String cmd, String msg, Team t)
{
  //println("EVENT, " + cmd + " / " + msg);
  String teamName = (t != null) ? t.longName : "";
  send_to_basestation(cmd);
  scoreClients.update_tEvent(cmd, msg, teamName);
  mslRemote.update_tEvent(cmd, msg, t);
}

void event_message(char team, boolean on, int pos) {
  if (on) {  //send to basestations
    if (team=='C' && pos<4){
      send_to_basestation(cCommcmds[pos]);
      scoreClients.update_tEvent("" + cCommcmds[pos], Commcmds[pos], "");
      mslRemote.update_tEvent("" + cCommcmds[pos], Commcmds[pos], null);
    } 
    else if (team=='A' && pos<10){
      send_to_basestation(cCTeamcmds[pos]);//<8
      scoreClients.update_tEvent("" + cCTeamcmds[pos], Teamcmds[pos], teamA.longName);
      mslRemote.update_tEvent("" + cCTeamcmds[pos], Teamcmds[pos], teamA);
    }
    else if (team=='B' && pos<10)
    {
      send_to_basestation(cMTeamcmds[pos]);//<8
      scoreClients.update_tEvent("" + cMTeamcmds[pos], Teamcmds[pos], teamB.longName);
      mslRemote.update_tEvent("" + cMTeamcmds[pos], Teamcmds[pos], teamB);
    }
  }
}

public static void test_send_direct(char team, int pos) {
  if (team=='C') BaseStationServer.write(cCommcmds[pos]);
  if (team=='A') BaseStationServer.write(cCTeamcmds[pos]);
  if (team=='B') BaseStationServer.write(cMTeamcmds[pos]);
}

public static void serverEvent(Server whichServer, Client whichClient) {
  if (whichServer.equals(BaseStationServer)) {
    println(getAbsoluteTime()+": New BaseStationClient @ "+whichClient.ip());
    if (!Popup.isEnabled()) {
      if(setteamfromip(whichClient.ip()))
        connectingClient = whichClient; 
      else
      {
        // Invalid team
        whichClient.write(COMM_RESET);
        BaseStationServer.disconnect(whichClient);
      }
    } else {
      whichClient.write(COMM_RESET);
      BaseStationServer.disconnect(whichClient);
    }
  }
  if (whichServer.equals(scoreClients.scoreServer))
    println(getAbsoluteTime()+": New ScoreClient @ " + whichClient.ip());
  if (whichServer.equals(mslRemote.server))
    println(getAbsoluteTime()+": New RemoteControl @ " + whichClient.ip());
}

public static boolean setteamfromip(String s) {
  String clientipstr="127.0.0.*";
  String[] iptokens;
  
  if (!s.equals("0:0:0:0:0:0:0:1")) {
    iptokens=split(s,'.');
    if (iptokens!=null) clientipstr=iptokens[0]+"."+iptokens[1]+"."+iptokens[2]+".*";
  }
  
  //println("Client IP: " + clientipstr);
  
  for (TableRow row : teamstable.rows()) {
    String saddr = row.getString("UnicastAddr");
    if (saddr.equals(clientipstr)) {
      println("Team " + row.getString("Team") + " connected (" + row.getString("shortname8") + "/" + row.getString("longame24") + ")");
      teamselect=row;
      
      if (!TESTMODE && StateMachine.GetCurrentGameState() == GameStateEnum.GS_PREGAME)
        Popup.show(PopupTypeEnum.POPUP_TEAMSELECTION, "Team: "+row.getString("Team")+"\nSelect color","cyan","magenta");
      
      return true;
    }
  }
  
  return false;
}

public static void checkBasestationsMessages()
{
  try
  {
    // Get the next available client
    Client thisClient = BaseStationServer.available();
    // If the client is not null, and says something, display what it said
    if (thisClient !=null) {
      
    Team t = null;
    int team = -1; // 0=A, 1=B
      if(teamA != null && teamA.IPBelongs(thisClient.ip()))
        t=teamA;
      else if(teamB != null && teamB.IPBelongs(thisClient.ip()))
        t=teamB;
      else{
        println("NON TEAM MESSAGE RECEIVED!!");
        return;
      }
    String whatClientSaid = new String(thisClient.readBytes());
    if (whatClientSaid != null) 
      while(whatClientSaid.length() !=0){
        //println(whatClientSaid);
        int idx = whatClientSaid.indexOf('\0');
        //println(whatClientSaid.length()+"\t"+ idx);
        if(idx!=-1){
          if(idx!=0)
          {  
            t.wsBuffer+= whatClientSaid.substring(0,idx);
            if(idx < whatClientSaid.length())
              whatClientSaid = whatClientSaid.substring(idx+1);
            else
              whatClientSaid = "";
          }else{
            if(whatClientSaid.length() == 1)
              whatClientSaid = "";
            else
              whatClientSaid = whatClientSaid.substring(1);
          }
          
          try
          {
            t.worldstate_json = new org.json.JSONObject(t.wsBuffer);
            int ageMs = t.worldstate_json.getInt("ageMs");
            t.logWorldstate(t.wsBuffer,ageMs);
            
            } catch(JSONException e) {
              if(t == teamA) println("ERROR from teamA : " + t.wsBuffer);
              else if(t == teamB) println("ERROR from teamB : " + t.wsBuffer);
          }
          t.wsBuffer="";      
          //println("NEW message");
        }else{
          t.wsBuffer+= whatClientSaid;
          break;
        }
        //println("MESSAGE from " + thisClient.ip() + ": " + whatClientSaid);
        
        // Avoid filling RAM with buffering (for example team is not sending the '\0' character)
        if(t.wsBuffer.length() > 100000)
          t.wsBuffer = "";
      }
      
      
    }
  }catch(Exception e){
  }
}


// -------------------------
// Referee Box Protocol 2015

// default commands
public static final char COMM_STOP = 'S';
public static final char COMM_START = 's';
public static final char COMM_WELCOME = 'W';  //NEW 2015CAMBADA: welcome message
public static final char COMM_WORLD_STATE = 'w';  //NEW 2015CAMBADA: request world state
public static final char COMM_RESET = 'Z';  //NEW 2015CAMBADA: Reset Game
public static final char COMM_TESTMODE_ON = 'U';  //NEW 2015CAMBADA: TestMode On
public static final char COMM_TESTMODE_OFF = 'u';  //NEW 2015CAMBADA: TestMode Off

// penalty Commands 
public static final char COMM_YELLOW_CARD_MAGENTA = 'y';  //NEW 2015CAMBADA: @remote
public static final char COMM_YELLOW_CARD_CYAN = 'Y';//NEW 2015CAMBADA: @remote
public static final char COMM_RED_CARD_MAGENTA = 'r';//NEW 2015CAMBADA: @remote
public static final char COMM_RED_CARD_CYAN = 'R';//NEW 2015CAMBADA: @remote
//public static final char COMM_DOUBLE_YELLOW_OUT_MAGENTA = 'b'; //NEW 2015CAMBADA: exits field
//public static final char COMM_DOUBLE_YELLOW_OUT_CYAN = 'B'; //NEW 2015CAMBADA:
public static final char COMM_DOUBLE_YELLOW_IN_MAGENTA = 'j'; //NEW 2015CAMBADA: 
public static final char COMM_DOUBLE_YELLOW_IN_CYAN = 'J'; //NEW 2015CAMBADA: 


// game flow commands
public static final char COMM_FIRST_HALF = '1';
public static final char COMM_SECOND_HALF = '2';
public static final char COMM_FIRST_HALF_OVERTIME = '3';  //NEW 2015CAMBADA: 
public static final char COMM_SECOND_HALF_OVERTIME = '4';  //NEW 2015CAMBADA: 
public static final char COMM_HALF_TIME = 'h';
public static final char COMM_END_GAME = 'e';    //ends 2nd part, may go into overtime
public static final char COMM_GAMEOVER = 'z';  //NEW 2015CAMBADA: Game Over
public static final char COMM_PARKING = 'L';

// goal status
public static final char COMM_GOAL_MAGENTA = 'a';
public static final char COMM_GOAL_CYAN = 'A';
public static final char COMM_SUBGOAL_MAGENTA = 'd';
public static final char COMM_SUBGOAL_CYAN = 'D';

// game flow commands
public static final char COMM_KICKOFF_MAGENTA = 'k';
public static final char COMM_KICKOFF_CYAN = 'K';
public static final char COMM_FREEKICK_MAGENTA = 'f';
public static final char COMM_FREEKICK_CYAN = 'F';
public static final char COMM_GOALKICK_MAGENTA = 'g';
public static final char COMM_GOALKICK_CYAN = 'G';
public static final char COMM_THROWIN_MAGENTA = 't';
public static final char COMM_THROWIN_CYAN = 'T';
public static final char COMM_CORNER_MAGENTA = 'c';
public static final char COMM_CORNER_CYAN = 'C';
public static final char COMM_PENALTY_MAGENTA = 'p';
public static final char COMM_PENALTY_CYAN = 'P';
public static final char COMM_DROPPED_BALL = 'N';

// repair Commands
public static final char COMM_REPAIR_OUT_MAGENTA = 'o';  //exits field
public static final char COMM_REPAIR_OUT_CYAN = 'O';
public static final char COMM_REPAIR_IN_MAGENTA = 'i';
public static final char COMM_REPAIR_IN_CYAN = 'I';

//  public static final char COMM_CANCEL = 'x'; //not used
//  public static final String COMM_RECONNECT_STRING = "Reconnect"; //not used

//free: fFHlmMnqQvVxX
//------------------------------------------------------

public static StringDict Description;
void comms_initDescriptionDictionary() {
  Description = new StringDict();
  Description.set("S", "STOP");
  Description.set("s", "START");
  Description.set("N", "Drop Ball");
  Description.set("h", "Halftime");
  Description.set("e", "End Game");
  Description.set("z", "Game Over");  //NEW 2015CAMBADA
  Description.set("Z", "Reset Game");  //NEW 2015CAMBADA
  Description.set("W", "Welcome");  //NEW 2015CAMBADA
  Description.set("w", "Request World State");  //NEW 2015CAMBADA
  Description.set("U", "Test Mode on");  //NEW 2015CAMBADA  ?
  Description.set("u", "Test Mode off");  //NEW 2015CAMBADA  ?
  Description.set("1", "1st half");
  Description.set("2", "2nd half");
  Description.set("3", "Overtime 1st half");  //NEW 2015CAMBADA
  Description.set("4", "Overtime 2nd half");  //NEW 2015CAMBADA
  Description.set("L", "Park");
  
  Description.set("K", "CYAN Kickoff");
  Description.set("F", "CYAN Freekick");
  Description.set("G", "CYAN Goalkick");
  Description.set("T", "CYAN Throw In");
  Description.set("C", "CYAN Corner");
  Description.set("P", "CYAN Penalty Kick");
  Description.set("A", "CYAN Goal+");
  Description.set("D", "CYAN Goal-");  
  Description.set("O", "CYAN Repair Out");
  Description.set("I", "CYAN Repair In");
  Description.set("R", "CYAN Red Card");  //NEW 2015CAMBADA
  Description.set("Y", "CYAN Yellow Card");  //NEW 2015CAMBADA
  Description.set("J", "CYAN Double Yellow in");  //NEW 2015CAMBADA
  //Description.set("B","CYAN Double Yellow out");  //NEW 2015CAMBADA

  Description.set("k", "MAGENTA Kickoff");
  Description.set("f", "MAGENTA Freekick");
  Description.set("g", "MAGENTA Goalkick");
  Description.set("t", "MAGENTA Throw In");
  Description.set("c", "MAGENTA Corner");
  Description.set("p", "MAGENTA Penalty Kick");
  Description.set("a", "MAGENTA Goal+");
  Description.set("d", "MAGENTA Goal-");
  Description.set("o", "MAGENTA Repair Out");
  Description.set("i", "MAGENTA Repair In");
  Description.set("r", "MAGENTA Red Card");  //NEW 2015CAMBADA
  Description.set("y", "MAGENTA Yellow Card");  //NEW 2015CAMBADA
  Description.set("j", "MAGENTA Double Yellow in");  //NEW 2015CAMBADA
  //Description.set("b","MAGENTA Double Yellow out");  //NEW 2015CAMBADA
}
