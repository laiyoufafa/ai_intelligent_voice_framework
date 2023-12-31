/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef INTELL_VOICE_MANAGER_NAPI_H
#define INTELL_VOICE_MANAGER_NAPI_H

#include <functional>
#include "napi/native_api.h"
#include "napi/native_node_api.h"

#include "intell_voice_manager.h"

namespace OHOS {
namespace IntellVoiceNapi {
using OHOS::IntellVoice::IntellVoiceManager;

class IntellVoiceManagerNapi {
public:
    IntellVoiceManagerNapi();
    ~IntellVoiceManagerNapi();

    static napi_value Export(napi_env env, napi_value exports);
    static napi_value CreateEnrollIntelligentVoiceEngine(napi_env env, napi_callback_info info);
    static napi_value CreateWakeupIntelligentVoiceEngine(napi_env env, napi_callback_info info);

private:
    static void Destructor(napi_env env, void *nativeObject, void *finalize_hint);
    static napi_value Constructor(napi_env env, napi_callback_info info);

    static napi_value GetCapabilityInfo(napi_env env, napi_callback_info info);
    static napi_value On(napi_env env, napi_callback_info info);
    static napi_value Off(napi_env env, napi_callback_info info);

    static napi_value GetIntelligentVoiceManager(napi_env env, napi_callback_info info);
    static napi_value GetIntelligentVoiceManagerWrapper(napi_env env);
    template<typename T> static napi_value CreatePropertyBase(napi_env env, T &propertyMap, napi_ref ref);

    napi_env env_ = nullptr;
    napi_ref wrapper_ = nullptr;
    IntellVoiceManager *manager_ = nullptr;
    static napi_ref serviceChangeTypeRef_;
    static napi_ref engineTypeRef_;
    static napi_ref sensibilityTypeRef_;
    static napi_ref enrollEventTypeRef_;
    static napi_ref wakeupEventTypeRef_;
    static napi_ref errorCodeRef_;
};
}  // namespace IntellVoiceNapi
}  // namespace OHOS
#endif
