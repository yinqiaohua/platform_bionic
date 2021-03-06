/*
 * Copyright (C) 2014 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#pragma once

#include <sys/cdefs.h>
#include <sys/ptrace.h>
#include <sys/ucontext.h>

__BEGIN_DECLS

#if defined(__arm__)
#define ELF_NGREG (sizeof(struct user_regs) / sizeof(elf_greg_t))
#elif defined(__aarch64__)
#define ELF_NGREG (sizeof(struct user_pt_regs) / sizeof(elf_greg_t))
#else
#define ELF_NGREG (sizeof(struct user_regs_struct) / sizeof(elf_greg_t))
#endif

typedef unsigned long elf_greg_t;
typedef elf_greg_t elf_gregset_t[ELF_NGREG];

typedef fpregset_t elf_fpregset_t;

#if defined(__i386__)
typedef struct user_fpxregs_struct elf_fpxregset_t;
#endif

typedef elf_gregset_t prgregset_t;
typedef elf_fpregset_t prfpregset_t;

typedef pid_t lwpid_t;
typedef void* psaddr_t;

struct elf_siginfo {
  int si_signo;
  int si_code;
  int si_errno;
};

#define ELF_PRARGSZ 80

__END_DECLS
