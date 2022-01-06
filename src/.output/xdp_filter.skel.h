/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __XDP_FILTER_BPF_SKEL_H__
#define __XDP_FILTER_BPF_SKEL_H__

#include <stdlib.h>
#include <bpf/libbpf.h>

struct xdp_filter_bpf {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
};

static void
xdp_filter_bpf__destroy(struct xdp_filter_bpf *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
xdp_filter_bpf__create_skeleton(struct xdp_filter_bpf *obj);

static inline struct xdp_filter_bpf *
xdp_filter_bpf__open_opts(const struct bpf_object_open_opts *opts)
{
	struct xdp_filter_bpf *obj;

	obj = (struct xdp_filter_bpf *)calloc(1, sizeof(*obj));
	if (!obj)
		return NULL;
	if (xdp_filter_bpf__create_skeleton(obj))
		goto err;
	if (bpf_object__open_skeleton(obj->skeleton, opts))
		goto err;

	return obj;
err:
	xdp_filter_bpf__destroy(obj);
	return NULL;
}

static inline struct xdp_filter_bpf *
xdp_filter_bpf__open(void)
{
	return xdp_filter_bpf__open_opts(NULL);
}

static inline int
xdp_filter_bpf__load(struct xdp_filter_bpf *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct xdp_filter_bpf *
xdp_filter_bpf__open_and_load(void)
{
	struct xdp_filter_bpf *obj;

	obj = xdp_filter_bpf__open();
	if (!obj)
		return NULL;
	if (xdp_filter_bpf__load(obj)) {
		xdp_filter_bpf__destroy(obj);
		return NULL;
	}
	return obj;
}

static inline int
xdp_filter_bpf__attach(struct xdp_filter_bpf *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
xdp_filter_bpf__detach(struct xdp_filter_bpf *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline int
xdp_filter_bpf__create_skeleton(struct xdp_filter_bpf *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		return -1;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "xdp_filter_bpf";
	s->obj = &obj->obj;

	s->data_sz = 368;
	s->data = (void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x70\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x04\0\x03\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2e\x74\x65\x78\x74\0\x2e\
\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x0f\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\
\0\0\x18\0\0\0\0\0\0\0\x03\0\0\0\x01\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\
\x07\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x58\0\0\0\0\0\0\0\x17\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -1;
}

#endif /* __XDP_FILTER_BPF_SKEL_H__ */
