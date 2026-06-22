#ifndef CONTROL_BLOCK_H
#define CONTROL_BLOCK_H

struct control_block
{
    int strong_ref_count = 0;
    int weak_ref_count   = 0;
};


#endif