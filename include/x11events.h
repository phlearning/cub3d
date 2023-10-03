/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x11events.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:15:24 by pvong             #+#    #+#             */
/*   Updated: 2023/10/02 18:21:52 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X11EVENTS_H
# define X11EVENTS_H

/*			EVENTS			*/

# define KEY_PRESS						02
# define KEY_RELEASE					03
# define BUTTON_PRESS					04
# define BUTTON_RELEASE					05
# define MOTION_NOTIFY					06
# define ENTER_NOTIFY					07
# define LEAVE_NOTIFY					08
# define FOCUS_IN						09
# define FOCUS_OUT						10
# define KEYMAP_NOTIFY					11
# define EXPOSE							12
# define GRAPHICS_EXPOSE				13
# define NO_EXPOSE						14
# define VISIBILITY_NOTIFY				15
# define CREATE_NOTIFY					16
# define DESTROY_NOTIFY					17
# define UNMAP_NOTIFY					18
# define MAP_NOTIFY						19
# define MAP_REQUEST					20
# define REPARENT_NOTIFY				21
# define CONFIGURE_NOTIFY				22
# define CONFIGURE_REQUEST				23
# define GRAVITY_NOTIFY					24
# define RESIZE_REQUEST					25
# define CIRCULATE_NOTIFY				26
# define CIRCULATE_REQUEST				27
# define PROPERTY_NOTIFY				28
# define SELECTION_CLEAR				29
# define SELECTION_REQUEST				30
# define SELECTION_NOTIFY				31
# define COLORMAP_NOTIFY				32
# define CLIENT_MESSAGE					33
# define MAPPING_NOTIFY					34
# define GENERIC_EVENT					35
# define LAST_EVENT						36

// # define NO_EVENT_MASK					0L
// # define KEY_PRESS_MASK					(1L<<0)
// # define KEY_RELEASE_MASK				(1L<<1)
// # define BUTTON_PRESS_MASK				(1L<<2)
// # define BUTTON_RELEASE_MASK				(1L<<3)
// # define ENTER_WINDOW_MASK				(1L<<4)
// # define LEAVE_WINDOW_MASK				(1L<<5)
// # define POINTER_MOTION_MASK				(1L<<6)
// # define POINTER_MOTION_HINT_MASK		(1L<<7)
// # define BUTTON_1_MOTION_MASK			(1L<<8)
// # define BUTTON_2_MOTION_MASK			(1L<<9)
// # define BUTTON_3_MOTION_MASK			(1L<<10)
// # define BUTTON_4_MOTION_MASK			(1L<<11)
// # define BUTTON_5_MOTION_MASK			(1L<<12)
// # define BUTTON_MOTION_MASK				(1L<<13)
// # define KEY_MAPSTATE_MASK				(1L<<14)
// # define EXPOSURE_MASK					(1L<<15)
// # define VISIBILITY_CHANGE_MASK			(1L<<16)
// # define STRUCTURE_NOTIFY_MASK			(1L<<17)
// # define RESIZE_REDIRECT_MASK			(1L<<18)
// # define SUBSTRUCTURE_NOTIFY_MASK		(1L<<19)
// # define SUBSTRUCTURE_REDIRECT_MASK		(1L<<20)
// # define FOCUS_CHANGE_MASK				(1L<<21)
// # define PROPERTY_CHANGE_MASK			(1L<<22)
// # define COLOR_MAP_CHANGE_MASK			(1L<<23)
// # define OWNER_GRAB_BUTTON_MASK			(1L<<24)

#endif