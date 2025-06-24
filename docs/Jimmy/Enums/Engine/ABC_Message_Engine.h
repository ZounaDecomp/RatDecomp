#ifndef ABC_MESSAGE_ENGINE_H
#define ABC_MESSAGE_ENGINE_H

typedef int abc_message;

enum {
    msg_no_message,

    msg_skel_collide,

    msg_anim_note_track_first, //Mark first message from NoteTrack
    msg_anim_loop,
    msg_anim_nosmooth,
    msg_anim_node_collide,
    msg_anim_node_uncollide,
    msg_anim_node_getorient,
    msg_anim_node_projectile_sent,
    msg_anim_orient,
    msg_anim_noorient,
    msg_anim_action,
    msg_anim_srept,
    msg_anim_erept,
    msg_anim_playsound,
    msg_anim_stopsound,
    msg_anim_playsoundrnd,
    msg_anim_playcdsound,
    msg_anim_playcdsoundloop,
    msg_anim_stopcdsound,
    msg_anim_nodynamic,
    msg_anim_dynamic,
    msg_anim_material_color,
    msg_anim_seqanim,
    msg_anim_active,
    msg_anim_setemiter,

    msg_anim_unknow_skel_collide,

    msg_anim_particles_efx,
    msg_anim_particles_efx_pause,
    msg_anim_particles_efx_reset,

    msg_rtc_start,
    msg_rtc_end,
    msg_rtc_changecamera,
    msg_rtc_picture,
    msg_rtc_no_picture,
    msg_rtc_mark,
    msg_rtc_letter_box_start,
    msg_rtc_letter_box_end,
    msg_rtc_letter_box_color,

    msg_anim_note_track_end, //Mark last message from NoteTrack

    msg_goto_length,
    msg_goto_curlength,
    msg_goto_2nd_vertex,
    msg_goto_end,

    msg_volume_in,
    msg_volume_out,
    msg_volume_stay,

    msg_menu3d_effect_end,
    msg_skin_selected,

    msg_carry_begin,
    msg_carry_end,

    msg_held_begin,
    msg_held_end,

    msg_thrown_begin,
    msg_thrown_end,

    msg_target_hit,
    msg_target_miss,

    msg_lod_collide,
    msg_decor_collide,

    msg_thrown_lod_collide,
    msg_thrown_decor_collide,

    msg_restore_collide,

    msg_sequenced_collide,

    msg_skin_act_begin,

    msg_skin_act_end,

    msg_bumper,

    msg_father_unlinked,

    msg_camera_capture_patch_start,
    msg_camera_capture_frame_start,
    msg_camera_capture_texture_start,
    msg_camera_capture_end,
    msg_camera_capture_param_1,
    msg_camera_capture_param_2,
    msg_camera_capture_param_3,

    msg_camera_reset_focus,

    msg_stream_end,
    msg_stream_error,
    msg_stream_resumed,
    msg_stream_resume_possible,

    msg_stream_abort,
    msg_stream_aborted,

    msg_game_activated,
    msg_game_reseted,

    msg_engine_end
};

#endif
