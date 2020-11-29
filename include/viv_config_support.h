#ifndef VIV_CONFIG_SUPPORT_H
#define VIV_CONFIG_SUPPORT_H

#define NULL_KEY 0
#define TERMINATE_KEYBINDS_LIST() {.key = NULL_KEY}

#define TERMINATE_LAYOUTS_LIST() {}

#define MAX_NUM_KEYBINDS 10000
#define MAX_WORKSPACE_NAME_LENGTH 80
#define MAX_NUM_WORKSPACES 50
#define MAX_NUM_LAYOUTS 50

#define KEYBIND_MAPPABLE(KEY, BINDING, ARGS...) \
    {                                           \
        .key = XKB_KEY_ ## KEY,                 \
        .binding = &viv_mappable_ ## BINDING,   \
        .payload = { .BINDING = { ARGS } }      \
    }

#define KEYBIND_USER_FUNCTION(KEY, BINDING)                     \
    {                                                           \
        .key = XKB_KEY_ ## KEY,                                 \
        .binding = &viv_mappable_user_function,                 \
        .payload = { .user_function = { .function = BINDING } } \
    }

#endif

#define EXIT_WITH_MESSAGE(MESSAGE)             \
    wlr_log(WLR_ERROR, MESSAGE);                  \
    exit(EXIT_FAILURE);

#define CHECK_ALLOCATION(POINTER)                           \
    if (!POINTER) {                                         \
        EXIT_WITH_MESSAGE("ALLOCATION FAILURE: " #POINTER); \
    }

#define ASSERT(EXPR)                                \
    if (!(EXPR)) {                                  \
        EXIT_WITH_MESSAGE("Assert failed: " #EXPR); \
    }

#define UNREACHABLE() \
    EXIT_WITH_MESSAGE("UNREACHABLE");

#define UNUSED(SYMBOL) \
    (void)(SYMBOL);