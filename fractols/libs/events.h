

#ifndef	EVENTS_H
#	define EVENTS_H

int on_destroy_event(t_config *config);
int on_mouse_hook_event(int key, int x, int y, t_config *config);
int on_mouse_move_event(int x, int y, t_config *config);
int on_key_hook_event(int key, t_config *config);

#	endif

