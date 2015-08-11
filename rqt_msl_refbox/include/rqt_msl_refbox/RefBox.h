#ifndef rqt_msl_refbox__RefBox_H
#define rqt_msl_refbox__RefBox_H

#include <rqt_gui_cpp/plugin.h>
#include <rqt_msl_refbox/GameData.h>
#include <ui_RefBox.h>

#include "ros/ros.h"
#include <ros/macros.h>

#include <QtGui>
#include <QWidget>
#include <QDialog>

namespace rqt_msl_refbox
{
	using namespace std;

	class GameData;
	class ItemDelegate : public QItemDelegate
	{
		virtual QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const
		{
			return QItemDelegate::sizeHint(option, index).expandedTo(QSize(0,10));
		}
	};
	class RefBox : public rqt_gui_cpp::Plugin, public Ui::RefBoxWidget
	{

	Q_OBJECT

	public:

		RefBox();

		virtual void initPlugin(qt_gui_cpp::PluginContext& context);

		virtual void shutdownPlugin();

		virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const;

		virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings);

		Ui::RefBoxWidget ui_;
		QWidget* widget_;
	private:
		GameData* gameData;
		bool eventFilter(QObject* watched, QEvent* event);
	};

}

#endif // rqt_msl_refbox__RefBox_H
