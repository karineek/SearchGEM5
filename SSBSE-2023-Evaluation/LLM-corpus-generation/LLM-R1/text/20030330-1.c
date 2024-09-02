// Modification timestamp: 2023-08-14 12:44:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030330-1.c
/* PR opt/10011 */
/* This is link test for builtin_constant_p simplification + DCE.  */

extern void link_error(void);
static void usb_hub_port_wait_reset(unsigned int delay)
{
        int delay_time;
        for (delay_time = 0; delay_time < 500; delay_time += delay) {
                if (__builtin_constant_p(delay))
                        link_error();
        }
}

int main() { return 0; }
