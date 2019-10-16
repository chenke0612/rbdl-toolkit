#ifndef TIMELINE_H_INCLUDED
#define TIMELINE_H_INCLUDED

#include <QWidget>
#include "ui_Timeline.h"

class ToolkitTimeline : public QWidget, public Ui::Timeline {
	Q_OBJECT
	private:
		float speed_factor;
		float max_time;
		float current_time;
		unsigned int slider_granularity;
		bool playing;
		bool was_playing;

	public:
		ToolkitTimeline(QWidget* parent);

		void setMaxTime(float max_time);
		void setCurrentTime(float current_time);
		void reset();

	public slots:
		void speedChanged(double speed);
		void togglePlaying();

		void sliderMoved(int pos);
		void sliderPressed();
		void sliderReleased();

		void tick(float dt);

	signals:
		//signal always sends absolute time so that all listeners can update accordingly
		void timeChanged(float current_time);
};

#endif 
