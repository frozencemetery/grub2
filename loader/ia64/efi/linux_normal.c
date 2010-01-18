/* linux_normal.c - boot linux */
/*
 *  GRUB  --  GRand Unified Bootloader
 *  Copyright (C) 2008  Free Software Foundation, Inc.
 *
 *  GRUB is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  GRUB is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GRUB.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <grub/machine/loader.h>
#include <grub/err.h>
#include <grub/normal.h>
#include <grub/dl.h>

static grub_err_t
grub_normal_linux_command (struct grub_arg_list *state __attribute__ ((unused)),
			   int argc, char **args)
{
  grub_rescue_cmd_linux (argc, args);
  return grub_errno;
}


static grub_err_t
grub_normal_initrd_command (struct grub_arg_list *state __attribute__ ((unused)),
			    int argc, char **args)
{
  grub_rescue_cmd_initrd (argc, args);
  return grub_errno;
}

static grub_err_t
grub_normal_cmd_payload (struct grub_arg_list *state __attribute__ ((unused)),
			int argc, char **args)
{
  grub_rescue_cmd_payload (argc, args);
  return grub_errno;
}

static grub_err_t
grub_normal_cmd_relocate (struct grub_arg_list *state __attribute__ ((unused)),
			int argc, char **args)
{
  grub_rescue_cmd_relocate (argc, args);
  return grub_errno;
}

static grub_err_t
grub_normal_cmd_fpswa (struct grub_arg_list *state __attribute__ ((unused)),
			int argc, char **args)
{
  grub_rescue_cmd_fpswa (argc, args);
  return grub_errno;
}

GRUB_MOD_INIT(linux_normal)
{
  (void) mod; /* To stop warning.  */
  grub_register_command
    ("linux", grub_normal_linux_command,
     GRUB_COMMAND_FLAG_BOTH | GRUB_COMMAND_FLAG_NO_ARG_PARSE,
     "linux FILE [ARGS...]",
     "Load a linux kernel.", 0);
  
  grub_register_command
    ("initrd", grub_normal_initrd_command,
     GRUB_COMMAND_FLAG_BOTH | GRUB_COMMAND_FLAG_NO_ARG_PARSE,
     "initrd FILE",
     "Load an initrd.", 0);

  grub_register_command
    ("payload", grub_normal_cmd_payload,
     GRUB_COMMAND_FLAG_BOTH | GRUB_COMMAND_FLAG_NO_ARG_PARSE,
     "payload FILE [ARGS...]",
     "Load an additional file.", 0);

  grub_register_command
    ("relocate", grub_normal_cmd_relocate,
     GRUB_COMMAND_FLAG_BOTH | GRUB_COMMAND_FLAG_NO_ARG_PARSE,
     "relocate [on|off|force]",
     "Set relocate feature.", 0);

  grub_register_command
    ("fpswa", grub_normal_cmd_fpswa,
     GRUB_COMMAND_FLAG_BOTH | GRUB_COMMAND_FLAG_NO_ARG_PARSE,
     "fpswa",
     "Display FPSWA version.", 0);
}

GRUB_MOD_FINI(linux_normal)
{
  grub_unregister_command ("linux");
  grub_unregister_command ("initrd");
  grub_unregister_command ("payload");
  grub_unregister_command ("relocate");
  grub_unregister_command ("fpswa");
}
