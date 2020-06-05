#include "SPakInfoWindow.h"

#include "EditorStyle.h"
#include "Styling/CoreStyle.h"

#define LOCTEXT_NAMESPACE "SPakInfoWindow"

SPakInfoWindow::SPakInfoWindow()
{

}

SPakInfoWindow::~SPakInfoWindow()
{

}

void SPakInfoWindow::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SBorder)
		.BorderImage(FEditorStyle::GetBrush("NotificationList.ItemBackground"))
		.Padding(8.0f)
		.HAlign(HAlign_Fill)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			.HAlign(HAlign_Left)
			.Padding(0.0f, 2.0f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("MountPointTitle", "Mount Point:"))
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
				.ColorAndOpacity(FLinearColor::Gray)
			]
		]

	];
}

#undef LOCTEXT_NAMESPACE
