#include "c_event_manager.hpp"
#include <sys/inotify.h>

c_event_manager::c_event_manager(const std::string &path_name) :
	m_fd(init_fd(path_name)),
	m_io_service(),
	m_dir_fd(m_io_service)
{
}

int c_event_manager::init_fd(const std::string &path_name) {
	int fd = inotify_init();
	if (fd == -1) throw std::runtime_error("inotify_init error");
	int wd = inotify_add_watch(fd, path_name.c_str(), IN_CREATE);
	if (wd == -1) throw std::runtime_error("inotify_add_watch error");


	return 0;
}
