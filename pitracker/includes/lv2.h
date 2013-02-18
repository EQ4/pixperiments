#ifndef PITRACKER_LV2_H
#define PITRACKER_LV2_H
#include <lv2/lv2plug.in/ns/lv2core/lv2.h>

LV2_Atom_Forge forge;

LV2_URID_Map lv2_urid_map;

#define MAX_FEATURES 3
const LV2_Feature* lv2_features[MAX_FEATURES];

#define MAX_PLUGINS 20
LV2_Descriptor *lv2_descriptors[MAX_PLUGINS];
LV2_Handle *lv2_handles[MAX_PLUGINS];

void lv2_init();


#define LV2_AUDIO_BUFFER_SIZE 0x40
#define LV2_ATOM_BUFFER_SIZE 256

enum lv2_port_type { lv2_audio_port, lv2_atom_port };

typedef struct {
    enum lv2_port_type type;
    uint32_t id;
    void *buffer;
    size_t buffer_sz;
} lv2_port;

lv2_port *new_lv2_port(enum lv2_port_type type, uint32_t id);
#endif
