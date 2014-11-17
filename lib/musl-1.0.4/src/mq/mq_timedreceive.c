#include <mqueue.h>
#include "syscall.h"

ssize_t mq_timedreceive(mqd_t mqd, char *restrict msg, size_t len, unsigned *restrict prio, const struct timespec *restrict at)
{
  return syscall_cp(SYS_mq_timedreceive, mqd, mcfi_sandbox_mask(msg), len, mcfi_sandbox_mask(prio), at);
}