#ifndef VDR_LIVE_WHATS_ON_H
#define VDR_LIVE_WHATS_ON_H

#include <ctime>
#include <vector>
#include <boost/shared_ptr.hpp>

#include <vdr/plugin.h>
#include <vdr/channels.h>
#include <vdr/epg.h>
#include <vdr/config.h>
#include <vdr/i18n.h>

#include "live.h"

namespace vdrlive
{

	class EpgEvent
	{
		public:
			EpgEvent(const std::string& id,
					 const std::string& caption,
					 const std::string& title,
					 const std::string& short_descr,
					 const std::string& long_descr,
					 time_t start_time,
					 time_t end_time);

			EpgEvent(const std::string& id,
					 const cEvent* event,
					 const char* channelName = "");

			virtual ~EpgEvent();

			const std::string& Id() const { return m_eventId; }

			const std::string& Title() const { return m_title; }

			const std::string& Caption() const { return m_caption; }

			const std::string& ShortDescr() const { return m_short_descr; }

			const std::string& LongDescr() const { return m_long_descr; }

			const std::string StartTime(const char* format) const;

			const std::string EndTime(const char* format) const;

		private:
			std::string m_eventId;
			std::string m_caption;
			std::string m_title;
			std::string m_short_descr;
			std::string m_long_descr;
			time_t m_start_time;
			time_t m_end_time;
	};

	typedef boost::shared_ptr<EpgEvent> EpgEventPtr;

	class EpgEvents : public std::vector<EpgEventPtr> {
		public:
			EpgEvents();
			virtual ~EpgEvents();

		private:
	};
}; // namespace vdrlive

#endif // VDR_LIVE_WHATS_ON_H
