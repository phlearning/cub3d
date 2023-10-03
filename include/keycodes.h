/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:15:07 by pvong             #+#    #+#             */
/*   Updated: 2023/10/02 12:23:07 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# ifdef __linux__
// French keyboard azerty

/*
** Keyboard LETTERS
*/

#  define K_A 113
#  define K_B 98
#  define K_C 99
#  define K_D 100
#  define K_E 101
#  define K_F 102
#  define K_G 103
#  define K_H 104
#  define K_I 105
#  define K_J 106
#  define K_K 107
#  define K_L 108
#  define K_M 44
#  define K_S 115
#  define K_T 116
#  define K_U 117
#  define K_V 118
#  define K_W 122
#  define K_X 120
#  define K_Y 121
#  define K_Z 119

/*
** Keyboard NUMBERS
*/

#  define K_NUM_1 38
#  define K_NUM_2 233
#  define K_NUM_3 34
#  define K_NUM_4 39
#  define K_NUM_5 40
#  define K_NUM_6 45
#  define K_NUM_7 232
#  define K_NUM_8 95
#  define K_NUM_9 231

/*
** Keyboard ARROWS
*/

#  define K_AR_L 65361
#  define K_AR_R 65363
#  define K_AR_U 65362
#  define K_AR_D 65364

/*
** Keyboard NUMPAD
*/

#  define K_NP_DIV 65455
#  define K_NP_MUL 65450
#  define K_NP_MIN 65453
#  define K_NP_PLU 65451
#  define K_NP_1	65436
#  define K_NP_2	65433
#  define K_NP_3	65435
#  define K_NP_4	65430
#  define K_NP_5	65437
#  define K_NP_6	65432
#  define K_NP_7	65429
#  define K_NP_8	65431
#  define K_NP_9	65434

/*
** Keyboard MISC
*/

#  define K_SP 32
#  define K_ESC 65307
#  define K_TAB 65289
#  define K_LSHIFT 65505

/*
** Mouse
*/

#  define M_CLK_L 1
#  define M_CLK_R 3
#  define M_CLK_M 2
#  define M_SCR_U 4
#  define M_SCR_D 5

# else

/*
** Keyboard LETTERS
*/

#  define K_A 0
#  define K_B 11
#  define K_C 8
#  define K_D 2
#  define K_E 14
#  define K_F 3
#  define K_G 5
#  define K_H 4
#  define K_I 34
#  define K_J 38
#  define K_K 40
#  define K_L 37
#  define K_M 46
#  define K_S 1
#  define K_T 17
#  define K_U 32
#  define K_V 9
#  define K_W 13
#  define K_X 7
#  define K_Y 16
#  define K_Z 6

/*
** Keyboard NUMBERS
*/

#  define K_NUM_1 18
#  define K_NUM_2 19
#  define K_NUM_3 20
#  define K_NUM_4 21
#  define K_NUM_5 23
#  define K_NUM_6 22
#  define K_NUM_7 26
#  define K_NUM_8 28

/*
** Keyboard ARROWS
*/

#  define K_AR_L 123
#  define K_AR_R 124
#  define K_AR_U 126
#  define K_AR_D 125

/*
** Keyboard NUMPAD
*/

#  define K_NP_DIV	75
#  define K_NP_MUL	67
#  define K_NP_MIN	78
#  define K_NP_PLU	69
#  define K_NP_1	83
#  define K_NP_2	84
#  define K_NP_3	85
#  define K_NP_4	86
#  define K_NP_5	87
#  define K_NP_6	88
#  define K_NP_7	89
#  define K_NP_8	91
#  define K_NP_9	92

/*
** Keyboard MISC
*/

#  define K_SP 49
#  define K_ESC 53
#  define K_TAB 48
#  define K_LSHIFT 257

/*
** Mouse
*/

#  define M_CLK_L 1
#  define M_CLK_R 2
#  define M_CLK_M 3
#  define M_SCR_U 4
#  define M_SCR_D 5

# endif
#endif
