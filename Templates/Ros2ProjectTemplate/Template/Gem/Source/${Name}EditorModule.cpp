// {BEGIN_LICENSE}
/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
// {END_LICENSE}

#include <${Name}ModuleInterface.h>
#include "${Name}EditorSystemComponent.h"

#include "${Name}SampleComponent.h"
namespace ${SanitizedCppName}
{
    class ${SanitizedCppName}EditorModule
        : public ${SanitizedCppName}ModuleInterface
    {
    public:
        AZ_RTTI(${SanitizedCppName}EditorModule, "${ModuleClassId}", ${SanitizedCppName}ModuleInterface);
        AZ_CLASS_ALLOCATOR(${SanitizedCppName}EditorModule, AZ::SystemAllocator, 0);

        ${SanitizedCppName}EditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                ${SanitizedCppName}EditorSystemComponent::CreateDescriptor(),
                ${SanitizedCppName}SampleComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<${SanitizedCppName}EditorSystemComponent>(),
            };
        }
    };
}// namespace ${SanitizedCppName}

AZ_DECLARE_MODULE_CLASS(Gem_${SanitizedCppName}, ${SanitizedCppName}::${SanitizedCppName}EditorModule)
