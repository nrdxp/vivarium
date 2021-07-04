#ifndef VIV_SEAT_H
#define VIV_SEAT_H

#include "viv_types.h"

struct viv_seat *viv_seat_create(struct viv_server *server, char *name);

void viv_seat_begin_interactive(struct viv_seat *seat, struct viv_view *view, enum viv_cursor_mode mode, uint32_t edges);

/// Give keyboard focus to the given surface
void viv_seat_focus_surface(struct viv_seat *seat, struct wlr_surface *surface);

/// Create a new viv_keyboard in the given seat
void viv_seat_create_new_keyboard(struct viv_seat *seat, struct wlr_input_device *device);

#endif