package exit_probe

import "C"

const source string = `
#include <uapi/linux/ptrace.h>
#include <linux/sched.h>
#include <linux/fs.h>

`