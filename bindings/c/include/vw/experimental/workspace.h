// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#pragma once

#include "exports.h"
#include "types.h"

#include "options.h"

#ifdef __cplusplus
extern "C"
{
#endif

  // TODO use destroy naming

  // TODO create_workspace
  VW_DLL_PUBLIC VWStatus create_workspace(vw_options*, bool skipModelLoad, trace_message_func trace_listener,
      void* trace_context, vw_workspace** output, VWErrorString*);
  VW_DLL_PUBLIC VWStatus create_workspace_with_model(vw_options*, void* context, read_func reader, bool skipModelLoad,
      trace_message_func trace_listener, void* trace_context, vw_workspace** output, VWErrorString*);
  VW_DLL_PUBLIC VWStatus seed_workspace(const vw_workspace*, vw_options* opts, trace_message_func trace_listener,
      void* trace_context, vw_workspace**, VWErrorString*);

  // Returns name of first incompatible feature.
  // TODO deprecate this...
  VWStatus are_features_compatible(const vw_workspace*, const vw_workspace*, vw_str*,
      VWErrorString*);  // Probably better to return an enum with enum->string mappings available?

  VW_DLL_PUBLIC VWStatus get_model_id(vw_workspace* all, const char**, VWErrorString*);
  VW_DLL_PUBLIC VWStatus set_model_id(vw_workspace* all, const char*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus get_command_line(vw_workspace* all, const char**, VWErrorString*);

  // finish is now broken up into finish() and destroy_workspace().
  VW_DLL_PUBLIC VWStatus finish(vw_workspace* all, VWErrorString*);
  VW_DLL_PUBLIC VWStatus destroy_workspace(vw_workspace* all, VWErrorString*);

  VW_DLL_PUBLIC VWStatus vw_get_pred_type(vw_workspace* vw, vw_prediction_type*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus vw_get_label_type(vw_workspace* vw, vw_label_type*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus learn(vw_workspace* vw, vw_example* example, VWErrorString*);
  VW_DLL_PUBLIC VWStatus learn_multiline(vw_workspace* vw, vw_example* example, size_t len, VWErrorString*);

  VW_DLL_PUBLIC VWStatus predict(vw_workspace* vw, vw_example* example, VWErrorString*);
  VW_DLL_PUBLIC VWStatus predict_multiline(vw_workspace* vw, vw_example* example, size_t len, VWErrorString*);

  // finish one or more examples? How do we handle multi_ex?
  VW_DLL_PUBLIC VWStatus finish_example(vw_workspace*, vw_example*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus finish_example_multiline(vw_workspace*, vw_example*, size_t, VWErrorString*);

  // End pass -> all.passes_complete++, in_pass_counter = 0; (something?)
  VW_DLL_PUBLIC VWStatus end_pass(vw_workspace* vw, VWErrorString*);

#ifdef __cplusplus
}
#endif
