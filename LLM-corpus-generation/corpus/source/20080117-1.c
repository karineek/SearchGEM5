// Modification timestamp: 2023-08-14 13:13:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20080117-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct gs_imager_state_s {
  struct {
    int half_width;
    int cap;
    float miter_limit;
  } line_params;
} gs_imager_state;

static const gs_imager_state gstate_initial = { { 1 } };

void gstate_path_memory(gs_imager_state *pgs) {
  *pgs = gstate_initial;
}

int gs_state_update_overprint(void) {
  return gstate_initial.line_params.half_width;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  gs_imager_state gstate;
  gstate_path_memory(&gstate);

  if (gs_state_update_overprint() != atoi(argv[1])) {
    abort();
  }

  return 0;
}
