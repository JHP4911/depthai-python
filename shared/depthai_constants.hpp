#pragma once
// TODO: this file should be removed, and all configurations passed to device via USB
// (e.g over config_h2d)


#include <climits>
#include <unordered_map>
#include <vector>

#include "stream/stream_info.hpp"

#include "metadata/frame_metadata.hpp"
#include "metadata/capture_metadata.hpp"


// TODO: remove next constant
std::unordered_map<std::string, StreamInfo> g_streams_pc_to_myriad =
{
    {"config_h2d",     StreamInfo("config_h2d",     5000)},
    {"host_capture",     StreamInfo("host_capture",     sizeof(CaptureMetadata))}
};


std::unordered_map<std::string, StreamInfo> c_streams_myriad_to_pc =
{
    {"left",        StreamInfo("left",      921600 + sizeof(FrameMetadata), { 720, 1280}    )},
    {"right",       StreamInfo("right",     921600 + sizeof(FrameMetadata), { 720, 1280}    )},
    {"disparity",   StreamInfo("disparity", 921600, { 720, 1280}    )},

    // {"depth",       StreamInfo("depth",     921600, { 720, 1280}    )},
    {"depth_sipp",  StreamInfo("depth_sipp",     0, { 720, 1280}, 2 )},
    {"depth_color_h", StreamInfo("depth_color_h",    720*1280*3, { 720, 1280, 3} )},

    {"metaout",     StreamInfo("metaout",    4*1024*1024)}, // 4 mb max metaout size
    {"previewout",  StreamInfo("previewout", 1920256)},

    {"meta_d2h",    StreamInfo("meta_d2h",   1024*1024)},
    {"jpegout",    StreamInfo("jpegout",   10*1024*1024)},
    {"video",    StreamInfo("video",   10*1024*1024)},
    {"object_tracker",    StreamInfo("object_tracker",   2000)}

};