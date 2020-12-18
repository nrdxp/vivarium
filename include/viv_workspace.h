
#ifndef VIV_WORKSPACE_H
#define VIV_WORKSPACE_H

#include "viv_types.h"

void viv_workspace_increment_divide(struct viv_workspace *workspace, float increment);

void viv_workspace_swap_out(struct viv_output *output, struct wl_list *workspaces);

void viv_workspace_focus_next_window(struct viv_workspace *workspace);
void viv_workspace_focus_prev_window(struct viv_workspace *workspace);

void viv_workspace_shift_active_window_down(struct viv_workspace *workspace);
void viv_workspace_shift_active_window_up(struct viv_workspace *workspace);

void viv_workspace_next_layout(struct viv_workspace *workspace);
void viv_workspace_prev_layout(struct viv_workspace *workspace);

/// Set the given output's workspace to the given workspace, switching with the previous
/// one if necessary
void viv_workspace_assign_to_output(struct viv_workspace *workspace, struct viv_output *output);


/// Returns the first non-floating view in the workspace, or NULL if there is none
struct viv_view *viv_workspace_main_view(struct viv_workspace *workspace);


/// Switches the current active window with the main window from the workspace
void viv_workspace_swap_active_and_main(struct viv_workspace *workspace);

/// Apply the layout function of the workspace, and handle tidying up e.g. pointer focus
void viv_workspace_do_layout(struct viv_workspace *workspace);

/// Apply the layout function of the workspace, but only if the workspace or its output needs layouting.
void viv_workspace_do_layout_if_necessary(struct viv_workspace *workspace);
#endif
