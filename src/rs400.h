// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2015 Intel Corporation. All Rights Reserved.

#pragma once
#ifndef LIBREALSENSE_RS400_H
#define LIBREALSENSE_RS400_H

#include "rs4xx.h"

namespace rsimpl
{
    // This classes represent RS4XX SKu that generate depth only data. There are 2 variants:
    // (1) DS5 PSR: Uses 2 RGB cameras (passive)
    // (2) DS5 ASR: Uses 2 IR cameras and an IR emitter (active)
    // The difference between the 2 variants is that DS4 ASR has extra controls for controlling the IR emitter

    class rs400_camera : public rs4xx_camera
    {

    public:
        rs400_camera(std::shared_ptr<uvc::device> device, const static_device_info & info);
        ~rs400_camera() {};

        void set_options(const rs_option options[], size_t count, const double values[]) override;
        void get_options(const rs_option options[], size_t count, double values[]) override;
        bool supports_option(rs_option option) const override;
        void get_option_range(rs_option option, double & min, double & max, double & step, double & def) override;
    };

    class rs410_camera final : public rs400_camera
    {

    public:
        rs410_camera(std::shared_ptr<uvc::device> device, const static_device_info & info);
        ~rs410_camera() {};

        void set_options(const rs_option options[], size_t count, const double values[]) override;
        void get_options(const rs_option options[], size_t count, double values[]) override;
    };

    std::shared_ptr<rs_device> make_rs410_device(std::shared_ptr<uvc::device> device);
    std::shared_ptr<rs_device> make_rs400_device(std::shared_ptr<uvc::device> device);
}

#endif