
#ifndef _ABC_CATEGORY_ENGINE_H_
#define _ABC_CATEGORY_ENGINE_H_
typedef int abc_category;

enum {
    cat_no_category = -1,

    cat_default,

    cat_check_thrown,
    cat_thrown,

    cat_running_rtc,
    cat_running_stream,
    cat_running_particles,

    cat_engine_end

};

#endif
