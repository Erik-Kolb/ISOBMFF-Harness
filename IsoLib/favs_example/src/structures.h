/*
This software module was originally developed by Apple Computer, Inc.
in the course of development of MPEG-4. 
This software module is an implementation of a part of one or 
more MPEG-4 tools as specified by MPEG-4. 
ISO/IEC gives users of MPEG-4 free license to this
software module or modifications thereof for use in hardware 
or software products claiming conformance to MPEG-4.
Those intending to use this software module in hardware or software
products are advised that its use may infringe existing patents.
The original developer of this software module and his/her company,
the subsequent editors and their companies, and ISO/IEC have no
liability for use of this software module or modifications thereof
in an implementation.
Copyright is not released for non MPEG-4 conforming
products. Apple Computer, Inc. retains full right to use the code for its own
purpose, assign or donate the code to a third party and to
inhibit third parties from using the code for non 
MPEG-4 conforming products.
This copyright notice must be included in all copies or
derivative works. Copyright (c) 1999.
*/

/* Created for Nokia FAVS project by Tampere University of Technology */

#ifndef INCLUDED_FAVS_STRUCTURES_H
#define INCLUDED_FAVS_STRUCTURES_H

typedef struct {
	u16 roll_count;
	u16 first_output_sample;
	u32 sample_offset[];
} alst_data, *alst_dataptr;

struct hevc_slice_header {
	s32 poc;
	s32 poc_offset;
	u32 sample_number;
	u32 slice_segment_address;
	u8 dependent_slice;
	u8 slice_type;
	u8 nal_type;
	u8 first_slice_segment_in_pic_flag;
	u32 num_entry_point_offsets;
	u32 *entry_point_offset_minus1;
	u32 num_slices;
	u32 *slice_offsets;
	u8 *aggregator_data;
	u32 aggregator_datalen;
	u16 aggregator_header;
};

struct hevc_poc {
	s32 order_cnt_msb;
	s32 order_cnt_lsb;
	u32 last_rap;
};


struct hevc_sps {
	u8 separate_color_plane_flag;
	u8 chroma_format_idc;
	u32 pic_width_in_luma_samples;
	u32 pic_height_in_luma_samples;
	u8 log2_max_pic_order_cnt_lsb_minus4;
	u8 sample_adaptive_offset_enabled_flag;
	u8 sps_temporal_mvp_enabled_flag;
	u8 long_term_ref_pics_present_flag;
	u8 num_long_term_ref_pics_sps;
	u8 num_short_term_ref_pic_sets;
	u8 slice_sao_luma_flag;
	u8 slice_sao_chroma_flag;
	u32 num_delta_pocs[32];
	u8 sps_max_sub_layers_minus1;
};

struct hevc_pps {
	u8 dependent_slice_segments_enabled_flag;
	u8 num_extra_slice_header_bits;
	u8 output_flag_present_flag;
	u8 tiles_enabled_flag;
	u8 num_tile_columns;
	u8 num_tile_rows;
	u8 tile_uniform_spacing_flag;
	u8 lists_modification_present_flag;
	u8 cabac_init_present_flag;
	u8 weighted_pred_flag;
	u8 weighted_bipred_flag;
	u8 pps_slice_chroma_qp_offsets_present_flag;
	u8 deblocking_filter_override_enabled_flag;
	u8 pps_loop_filter_across_slices_enabled_flag;
	u8 entropy_coding_sync_enabled_flag;
	u16 tile_column_width_minus1[16];
	u16 tile_row_height_minus1[16];
	u16 num_ref_idx_l0_default_active_minus1;
	u16 num_ref_idx_l1_default_active_minus1;
};

struct hevc_stream {
	u32 used_count;
	u32 allocated_count;
	struct hevc_slice_header **header;
	struct hevc_sps sps;
	struct hevc_pps pps;
};
/* whole loads of bitBuffer stuff for parsing parameter sets */

typedef struct {
	u8 *ptr;
	u32 length;
	u8 *cptr;
	u8 cbyte;
	u32 curbits;
	u32 bits_left;

	u8 prevent_emulation;	/* true or false */
	u8 emulation_position;	/* 0 usually, 1 after 1 zero byte, 2 after 2 zero bytes,
													3 after 00 00 03, and the 3 gets stripped */
} BitBuffer;

struct TrackGroup {
	u32 track;
	u32 track_group_id;
};

struct ParamStruct {
	u8 inputCount;
	char **inputs;
	char *output;

	double framerate;
	u32 frameduration;
	u32 seek;
	u8 trackGroupCount;
	struct TrackGroup **trackGroups;

	u32 subsample_information;
	u32 compactSampleToGroup;
};


#endif
