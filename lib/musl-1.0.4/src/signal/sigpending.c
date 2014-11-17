#include <signal.h>
#include "syscall.h"

int sigpending(sigset_t *set)
{
  return syscall(SYS_rt_sigpending, mcfi_sandbox_mask(set), _NSIG/8);
}
