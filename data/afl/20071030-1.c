// Modification timestamp: 2023-08-14 13:10:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20071030-1.c

#include <stdio.h>
#include <stdlib.h>

extern void *memset(void *, int, size_t);
extern void abort(void);

typedef struct
{
    unsigned char colormod;
} entity_state_t;

typedef struct
{
    int num_entities;
    entity_state_t *entities;
} packet_entities_t;

typedef struct
{
    double senttime;
    float ping_time;
    packet_entities_t entities;
} client_frame_t;

typedef enum
{
    cs_free,
    cs_server,
    cs_zombie,
    cs_connected,
    cs_spawned
} sv_client_state_t;

typedef struct client_s
{
    sv_client_state_t state;
    int ping;
    client_frame_t frames[64];
} client_t;

int CalcPing(client_t *cl)
{
    float ping;
    int count, i;
    register client_frame_t *frame;

    if (cl->state == cs_server)
        return cl->ping;
    ping = 0;
    count = 0;
    for (frame = cl->frames, i = 0; i < 64; i++, frame++)
    {
        if (frame->ping_time > 0)
        {
            ping += frame->ping_time;
            count++;
        }
    }
    if (!count)
        return 9999;
    ping /= count;

    return ping * 1000;
}

int main(int argc, char *argv[])
{
    client_t cl;

    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    memset(&cl, 0, sizeof(cl));

    cl.frames[0].ping_time = atof(argv[1]);

    if (CalcPing(&cl) != 1000)
        abort();

    return 0;
}
