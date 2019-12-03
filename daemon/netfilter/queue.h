#ifndef _NETFILTER_QUEUE_H
#define _NETFILTER_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <unistd.h>
#include <netinet/in.h>
#include <linux/types.h>
#include <linux/socket.h>
#include <linux/netfilter.h>
#include <libnetfilter_queue/libnetfilter_queue.h>

#ifndef NFQA_CFG_F_UID_GID
#define NFQA_CFG_F_UID_GID                      (1 << 3)
uint32_t nfq_get_uid(void *buffer, void *buffer2);
#endif

typedef struct {
    uint verdict;
    uint mark;
    uint mark_set;
    uint length;
    unsigned char *data;
} verdictContainer;

extern void go_callback(int id, unsigned char* data, int len, uint mark, u_int32_t idx, verdictContainer *vc, uint32_t uid);

int nf_callback(struct nfq_q_handle *qh, struct nfgenmsg *nfmsg, struct nfq_data *nfa, void *arg);

struct nfq_q_handle* CreateQueue(struct nfq_handle *h, u_int16_t queue, u_int32_t idx);

int Run(struct nfq_handle *h, int fd);

#endif
