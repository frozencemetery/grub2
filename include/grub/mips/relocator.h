/*
 *  GRUB  --  GRand Unified Bootloader
 *  Copyright (C) 2009  Free Software Foundation, Inc.
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

#ifndef GRUB_RELOCATOR_CPU_HEADER
#define GRUB_RELOCATOR_CPU_HEADER	1

#include <grub/types.h>
#include <grub/err.h>

struct grub_relocator32_state
{
  /* gpr[0] is ignored since it's hardwired to 0.  */
  grub_uint32_t gpr[32];
  /* Register holding target $pc.  */
  int jumpreg;
};

void *grub_relocator32_alloc (grub_size_t size);
grub_err_t grub_relocator32_boot (void *relocator, grub_uint32_t dest,
				  struct grub_relocator32_state state);
void *grub_relocator32_realloc (void *relocator, grub_size_t size);
void grub_relocator32_free (void *relocator);

#endif /* ! GRUB_RELOCATOR_CPU_HEADER */
