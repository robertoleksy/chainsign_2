#ifndef C_EVENT_MANAGER_HPP
#define C_EVENT_MANAGER_HPP

#include <boost/asio.hpp>
#include <string>

class c_event_manager final {
	public:
		c_event_manager(const std::string &path_name);
	private:
		int m_fd;
		boost::asio::io_service m_io_service;
		boost::asio::posix::stream_descriptor m_dir_fd;
		int init_fd(const std::string &path_name);
};

#endif // C_EVENT_MANAGER_HPP
