/* GStreamer
 * Copyright (C) 2023 Seungha Yang <seungha@centricular.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#pragma once

#include <gst/gst.h>
#include "gstd3d12device.h"
#include "gstd3d12format.h"

#define GST_D3D12_ALL_FORMATS \
    "{ NV12, P010_10LE, P016_LE }"

#define MAKE_FORMAT_MAP_YUV(g,d,r0,r1,r2,r3) \
  { GST_VIDEO_FORMAT_ ##g, DXGI_FORMAT_ ##d, \
    { DXGI_FORMAT_ ##r0, DXGI_FORMAT_ ##r1, DXGI_FORMAT_ ##r2, DXGI_FORMAT_ ##r3 }, \
    { DXGI_FORMAT_ ##r0, DXGI_FORMAT_ ##r1, DXGI_FORMAT_ ##r2, DXGI_FORMAT_ ##r3 }, \
    (D3D12_FORMAT_SUPPORT1) (D3D12_FORMAT_SUPPORT1_RENDER_TARGET | D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE) }

#define MAKE_FORMAT_MAP_FULL(g,d,r0,r1,r2,r3,f) \
  { g, DXGI_FORMAT_ ##d, \
    { DXGI_FORMAT_ ##r0, DXGI_FORMAT_ ##r1, DXGI_FORMAT_ ##r2, DXGI_FORMAT_ ##r3 }, \
    { DXGI_FORMAT_ ##r0, DXGI_FORMAT_ ##r1, DXGI_FORMAT_ ##r2, DXGI_FORMAT_ ##r3 }, \
    (D3D12_FORMAT_SUPPORT1) (f) }

#define MAKE_FORMAT_MAP_RGB(g,d) \
  { GST_VIDEO_FORMAT_ ##g, DXGI_FORMAT_ ##d, \
    { DXGI_FORMAT_ ##d, DXGI_FORMAT_UNKNOWN, DXGI_FORMAT_UNKNOWN, DXGI_FORMAT_UNKNOWN }, \
    { DXGI_FORMAT_ ##d, DXGI_FORMAT_UNKNOWN, DXGI_FORMAT_UNKNOWN, DXGI_FORMAT_UNKNOWN }, \
    (D3D12_FORMAT_SUPPORT1) (D3D12_FORMAT_SUPPORT1_RENDER_TARGET | D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE) }

#define MAKE_FORMAT_MAP_RGBP(g,d,a) \
  { GST_VIDEO_FORMAT_ ##g, DXGI_FORMAT_UNKNOWN, \
    { DXGI_FORMAT_ ##d, DXGI_FORMAT_ ##d, DXGI_FORMAT_ ##d, DXGI_FORMAT_ ##a }, \
    { DXGI_FORMAT_ ##d, DXGI_FORMAT_ ##d, DXGI_FORMAT_ ##d, DXGI_FORMAT_ ##a }, \
    (D3D12_FORMAT_SUPPORT1) (D3D12_FORMAT_SUPPORT1_RENDER_TARGET | D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE) }

static const GstD3D12Format g_gst_d3d12_default_format_map[] = {
  MAKE_FORMAT_MAP_RGB (BGRA, B8G8R8A8_UNORM),
  MAKE_FORMAT_MAP_RGB (RGBA, R8G8B8A8_UNORM),
  MAKE_FORMAT_MAP_RGB (BGRx, B8G8R8A8_UNORM),
  MAKE_FORMAT_MAP_RGB (RGBx, R8G8B8A8_UNORM),
  MAKE_FORMAT_MAP_RGB (ARGB, R8G8B8A8_UNORM),
  MAKE_FORMAT_MAP_RGB (xRGB, R8G8B8A8_UNORM),
  MAKE_FORMAT_MAP_RGB (ABGR, R8G8B8A8_UNORM),
  MAKE_FORMAT_MAP_RGB (xBGR, R8G8B8A8_UNORM),
  MAKE_FORMAT_MAP_RGB (RGB10A2_LE, R10G10B10A2_UNORM),
  MAKE_FORMAT_MAP_RGB (RGBA64_LE, R16G16B16A16_UNORM),
  MAKE_FORMAT_MAP_YUV (AYUV, UNKNOWN, R8G8B8A8_UNORM, UNKNOWN, UNKNOWN, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (AYUV64, UNKNOWN, R16G16B16A16_UNORM, UNKNOWN, UNKNOWN, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (VUYA, AYUV, R8G8B8A8_UNORM, UNKNOWN, UNKNOWN, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (NV12, NV12, R8_UNORM, R8G8_UNORM, UNKNOWN, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (NV21, UNKNOWN, R8_UNORM, R8G8_UNORM, UNKNOWN, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (P010_10LE, P010, R16_UNORM, R16G16_UNORM, UNKNOWN, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (P012_LE, P016, R16_UNORM, R16G16_UNORM, UNKNOWN, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (P016_LE, P016, R16_UNORM, R16G16_UNORM, UNKNOWN, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (I420, UNKNOWN, R8_UNORM, R8_UNORM, R8_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (YV12, UNKNOWN, R8_UNORM, R8_UNORM, R8_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (I420_10LE, UNKNOWN, R16_UNORM, R16_UNORM, R16_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (I420_12LE, UNKNOWN, R16_UNORM, R16_UNORM, R16_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (Y42B, UNKNOWN, R8_UNORM, R8_UNORM, R8_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (I422_10LE, UNKNOWN, R16_UNORM, R16_UNORM, R16_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (I422_12LE, UNKNOWN, R16_UNORM, R16_UNORM, R16_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (Y444, UNKNOWN, R8_UNORM, R8_UNORM, R8_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (Y444_10LE, UNKNOWN, R16_UNORM, R16_UNORM, R16_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (Y444_12LE, UNKNOWN, R16_UNORM, R16_UNORM, R16_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (Y444_16LE, UNKNOWN, R16_UNORM, R16_UNORM, R16_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (UYVY, UNKNOWN, R8G8B8A8_UNORM, UNKNOWN, UNKNOWN, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (VYUY, UNKNOWN, R8G8B8A8_UNORM, UNKNOWN, UNKNOWN, UNKNOWN),
  MAKE_FORMAT_MAP_YUV (YVYU, UNKNOWN, R8G8B8A8_UNORM, UNKNOWN, UNKNOWN, UNKNOWN),
  MAKE_FORMAT_MAP_RGB (GRAY8, R8_UNORM),
  MAKE_FORMAT_MAP_RGB (GRAY16_LE, R16_UNORM),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_Y410, Y410,
      R10G10B10A2_UNORM, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_BGR10A2_LE, Y410,
      R10G10B10A2_UNORM, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_YUY2, YUY2,
      R8G8B8A8_UNORM, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_Y210, Y210,
      R16G16B16A16_UNORM, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_Y212_LE, Y216,
      R16G16B16A16_UNORM, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_Y412_LE, Y416,
      R16G16B16A16_UNORM, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_BGRA64_LE, Y416,
      R16G16B16A16_UNORM, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_RGB, UNKNOWN,
      R8G8B8A8_UNORM, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_BGR, UNKNOWN,
      R8G8B8A8_UNORM, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_v210, UNKNOWN,
      R10G10B10A2_UNORM, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_v216, UNKNOWN,
      R16G16B16A16_UNORM, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_v308, UNKNOWN,
      R8G8B8A8_UNORM, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_IYU2, UNKNOWN,
      R8G8B8A8_UNORM, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_RGB16, UNKNOWN,
      R16_UINT, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_BGR16, UNKNOWN,
      R16_UINT, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_RGB15, UNKNOWN,
      R16_UINT, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_BGR15, UNKNOWN,
      R16_UINT, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_r210, UNKNOWN,
      R32_UINT, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_FULL (GST_VIDEO_FORMAT_RBGA, AYUV,
      R8G8B8A8_UNORM, UNKNOWN, UNKNOWN, UNKNOWN,
      D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE),
  MAKE_FORMAT_MAP_RGBP (RGBP, R8_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_RGBP (BGRP, R8_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_RGBP (GBR, R8_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_RGBP (GBR_10LE, R16_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_RGBP (GBR_12LE, R16_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_RGBP (GBR_16LE, R16_UNORM, UNKNOWN),
  MAKE_FORMAT_MAP_RGBP (GBRA, R8_UNORM, R8_UNORM),
  MAKE_FORMAT_MAP_RGBP (GBRA_10LE, R16_UNORM, R16_UNORM),
  MAKE_FORMAT_MAP_RGBP (GBRA_12LE, R16_UNORM, R16_UNORM),
};

#undef MAKE_FORMAT_MAP_YUV
#undef MAKE_FORMAT_MAP_FULL
#undef MAKE_FORMAT_MAP_RGB
#undef MAKE_FORMAT_MAP_RGBP

#define GST_D3D12_N_FORMATS G_N_ELEMENTS(g_gst_d3d12_default_format_map)
