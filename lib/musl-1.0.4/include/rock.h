#ifndef __ROCK_H
#define __ROCK_H

#define ROCK_OFFSET  2
#define ROCK_VERIFY  4
#define ROCK_COPY    8
#define ROCK_REPLACE 16

#define ROCK_FUNC_SYM       0
#define ROCK_ICJ            1
#define ROCK_ICJ_SYM        2
#define ROCK_RAI            3
#define ROCK_ICJ_UNREG      4
#define ROCK_ICJ_SYM_UNREG  5
#define ROCK_RAI_UNREG      6
#define ROCK_FUNC_SYM_UNREG 7
#define ROCK_RET            8

#ifdef __cplusplus
extern "C" {
#endif
  void rock_reg_cfg_metadata(const void *h, int type, const void *md, const void *extra);
  void *rock_create_code_heap(void **ph, unsigned long size, const void* verifier);
  void rock_delete_code(const void *h, const void *addr, unsigned long length);
  void rock_move_code(const void *h, const void *target, const void *source, unsigned long length);
  void rock_code_heap_fill(void *h, void *dst, const void *src,
                           unsigned long len, const void *extra);
#ifdef __cplusplus
}
#endif
#endif
