#include "SPakSummaryView.h"

#include "EditorStyle.h"
#include "IPlatformFilePak.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Layout/SExpandableArea.h"

#include "PakAnalyzerModule.h"
#include "SKeyValueRow.h"

#define LOCTEXT_NAMESPACE "SPakSummaryView"

SPakSummaryView::SPakSummaryView()
{

}

SPakSummaryView::~SPakSummaryView()
{

}

void SPakSummaryView::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SExpandableArea)
		.InitiallyCollapsed(true)
		.AreaTitle(LOCTEXT("PakSumary", "Pak Summary"))
		.BodyContent()
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.FillWidth(1.f)
			.Padding(2.0f)
			[
				SNew(SVerticalBox)

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0.f, 0.f)
				[
					SNew(SKeyValueRow).KeyText(LOCTEXT("Detail_View_Pak_Path", "Pak Path:")).ValueText(this, &SPakSummaryView::GetPakPath)
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0.f, 0.f)
				[
					SNew(SKeyValueRow).KeyText(LOCTEXT("Detail_View_Pak_MountPoint", "Mount Point:")).ValueText(this, &SPakSummaryView::GetPakMountPoint)
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0.f, 0.f)
				[
					SNew(SKeyValueRow).KeyText(LOCTEXT("Detail_View_Pak_Version", "Pak Version:")).ValueText(this, &SPakSummaryView::GetPakVersion)
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0.f, 0.f)
				[
					SNew(SKeyValueRow).KeyText(LOCTEXT("Detail_View_Pak_FileSize", "Pak File Size:")).ValueText(this, &SPakSummaryView::GetPakFileSize).ValueToolTipText(this, &SPakSummaryView::GetPakFileSizeToolTip)
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0.f, 0.f)
				[
					SNew(SKeyValueRow).KeyText(LOCTEXT("Detail_View_Pak_FileCount", "Pak File Count:")).ValueText(this, &SPakSummaryView::GetPakFileCount)
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0.f, 0.f)
				[
					SNew(SKeyValueRow).KeyText(LOCTEXT("Detail_View_Pak_HeaderSize", "Pak Header Size:")).ValueText(this, &SPakSummaryView::GetPakHeaderSize).ValueToolTipText(this, &SPakSummaryView::GetPakHeaderSizeToolTip)
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0.f, 0.f)
				[
					SNew(SKeyValueRow).KeyText(LOCTEXT("Detail_View_Pak_IndexSize", "Pak Index Size:")).ValueText(this, &SPakSummaryView::GetPakIndexSize).ValueToolTipText(this, &SPakSummaryView::GetPakIndexSizeToolTip)
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0.f, 0.f)
				[
					SNew(SKeyValueRow).KeyText(LOCTEXT("Detail_View_Pak_IndexHash", "Pak Index Hash:")).ValueText(this, &SPakSummaryView::GetPakFileIndexHash)
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0.f, 0.f)
				[
					SNew(SKeyValueRow).KeyText(LOCTEXT("Detail_View_Pak_IndexEncrypted", "Pak Index Is Encrypted:")).ValueText(this, &SPakSummaryView::GetPakFileIndexIsEncrypted)
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0.f, 0.f)
				[
					SNew(SKeyValueRow).KeyText(LOCTEXT("Detail_View_Pak_FileContentSize", "Pak File Content Size:")).ValueText(this, &SPakSummaryView::GetPakFileContentSize).ValueToolTipText(this, &SPakSummaryView::GetPakFileContentSizeToolTip)
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0.f, 0.f)
				[
					SNew(SKeyValueRow).KeyText(LOCTEXT("Detail_View_Pak_CompressionMethods", "Pak Compression Methods:")).ValueText(this, &SPakSummaryView::GetPakFileEncryptionMethods)
				]
			]

			//+ SHorizontalBox::Slot()
			//.FillWidth(1.f)
			//.Padding(2.0f)
			//[
			//]
		]
	];
}

FORCEINLINE FText SPakSummaryView::GetPakPath() const
{
	TSharedPtr<IPakAnalyzer> PakAnalyzer = IPakAnalyzerModule::Get().GetPakAnalyzer();

	return PakAnalyzer.IsValid() ? FText::FromString(PakAnalyzer->GetPakFileSumary().PakFilePath) : FText();
}

FORCEINLINE FText SPakSummaryView::GetPakMountPoint() const
{
	TSharedPtr<IPakAnalyzer> PakAnalyzer = IPakAnalyzerModule::Get().GetPakAnalyzer();

	return PakAnalyzer.IsValid() ? FText::FromString(PakAnalyzer->GetPakFileSumary().MountPoint) : FText();
}

FORCEINLINE FText SPakSummaryView::GetPakVersion() const
{
	TSharedPtr<IPakAnalyzer> PakAnalyzer = IPakAnalyzerModule::Get().GetPakAnalyzer();
	const FPakInfo* PakInfo = PakAnalyzer.IsValid() ? PakAnalyzer->GetPakFileSumary().PakInfo : nullptr;

	return PakInfo ? FText::AsNumber(PakInfo->Version) : FText();
}

FORCEINLINE FText SPakSummaryView::GetPakFileSize() const
{
	TSharedPtr<IPakAnalyzer> PakAnalyzer = IPakAnalyzerModule::Get().GetPakAnalyzer();

	return PakAnalyzer.IsValid() ? FText::AsMemory(PakAnalyzer->GetPakFileSumary().PakFileSize, EMemoryUnitStandard::IEC) : FText();
}

FORCEINLINE FText SPakSummaryView::GetPakFileSizeToolTip() const
{
	TSharedPtr<IPakAnalyzer> PakAnalyzer = IPakAnalyzerModule::Get().GetPakAnalyzer();

	return PakAnalyzer.IsValid() ? FText::AsNumber(PakAnalyzer->GetPakFileSumary().PakFileSize) : FText();
}

FORCEINLINE FText SPakSummaryView::GetPakFileCount() const
{
	TSharedPtr<IPakAnalyzer> PakAnalyzer = IPakAnalyzerModule::Get().GetPakAnalyzer();

	return PakAnalyzer.IsValid() ? FText::AsNumber(PakAnalyzer->GetFileCount()) : FText();
}

FORCEINLINE FText SPakSummaryView::GetPakHeaderSize() const
{
	TSharedPtr<IPakAnalyzer> PakAnalyzer = IPakAnalyzerModule::Get().GetPakAnalyzer();
	const FPakInfo* PakInfo = PakAnalyzer.IsValid() ? PakAnalyzer->GetPakFileSumary().PakInfo : nullptr;

	return PakInfo ? FText::AsMemory(PakAnalyzer->GetPakFileSumary().PakFileSize - PakInfo->IndexOffset - PakInfo->IndexSize, EMemoryUnitStandard::IEC) : FText();
}

FORCEINLINE FText SPakSummaryView::GetPakHeaderSizeToolTip() const
{
	TSharedPtr<IPakAnalyzer> PakAnalyzer = IPakAnalyzerModule::Get().GetPakAnalyzer();
	const FPakInfo* PakInfo = PakAnalyzer.IsValid() ? PakAnalyzer->GetPakFileSumary().PakInfo : nullptr;

	return PakInfo ? FText::AsNumber(PakAnalyzer->GetPakFileSumary().PakFileSize - PakInfo->IndexOffset - PakInfo->IndexSize) : FText();

}

FORCEINLINE FText SPakSummaryView::GetPakIndexSize() const
{
	TSharedPtr<IPakAnalyzer> PakAnalyzer = IPakAnalyzerModule::Get().GetPakAnalyzer();
	const FPakInfo* PakInfo = PakAnalyzer.IsValid() ? PakAnalyzer->GetPakFileSumary().PakInfo : nullptr;

	return PakInfo ? FText::AsMemory(PakInfo->IndexSize, EMemoryUnitStandard::IEC) : FText();
}

FORCEINLINE FText SPakSummaryView::GetPakIndexSizeToolTip() const
{
	TSharedPtr<IPakAnalyzer> PakAnalyzer = IPakAnalyzerModule::Get().GetPakAnalyzer();
	const FPakInfo* PakInfo = PakAnalyzer.IsValid() ? PakAnalyzer->GetPakFileSumary().PakInfo : nullptr;

	return PakInfo ? FText::AsNumber(PakInfo->IndexSize) : FText();
}

FORCEINLINE FText SPakSummaryView::GetPakFileIndexHash() const
{
	TSharedPtr<IPakAnalyzer> PakAnalyzer = IPakAnalyzerModule::Get().GetPakAnalyzer();
	const FPakInfo* PakInfo = PakAnalyzer.IsValid() ? PakAnalyzer->GetPakFileSumary().PakInfo : nullptr;
	
	return PakInfo ? FText::FromString(LexToString(PakInfo->IndexHash)) : FText();
}

FORCEINLINE FText SPakSummaryView::GetPakFileIndexIsEncrypted() const
{
	TSharedPtr<IPakAnalyzer> PakAnalyzer = IPakAnalyzerModule::Get().GetPakAnalyzer();
	const FPakInfo* PakInfo = PakAnalyzer.IsValid() ? PakAnalyzer->GetPakFileSumary().PakInfo : nullptr;

	return PakInfo ? FText::FromString(PakInfo->bEncryptedIndex ? TEXT("True") : TEXT("False")) : FText();
}

FORCEINLINE FText SPakSummaryView::GetPakFileContentSize() const
{
	TSharedPtr<IPakAnalyzer> PakAnalyzer = IPakAnalyzerModule::Get().GetPakAnalyzer();
	const FPakInfo* PakInfo = PakAnalyzer.IsValid() ? PakAnalyzer->GetPakFileSumary().PakInfo : nullptr;

	return PakInfo ? FText::AsMemory(PakInfo->IndexOffset, EMemoryUnitStandard::IEC) : FText();
}

FORCEINLINE FText SPakSummaryView::GetPakFileContentSizeToolTip() const
{
	TSharedPtr<IPakAnalyzer> PakAnalyzer = IPakAnalyzerModule::Get().GetPakAnalyzer();
	const FPakInfo* PakInfo = PakAnalyzer.IsValid() ? PakAnalyzer->GetPakFileSumary().PakInfo : nullptr;

	return PakInfo ? FText::AsNumber(PakInfo->IndexOffset) : FText();
}

FORCEINLINE FText SPakSummaryView::GetPakFileEncryptionMethods() const
{
	TSharedPtr<IPakAnalyzer> PakAnalyzer = IPakAnalyzerModule::Get().GetPakAnalyzer();
	const FPakInfo* PakInfo = PakAnalyzer.IsValid() ? PakAnalyzer->GetPakFileSumary().PakInfo : nullptr;

	TArray<FString> Methods;
	if (PakInfo)
	{
		for (const FName& Name : PakInfo->CompressionMethods)
		{
			Methods.Add(Name.ToString());
		}
	}

	return PakInfo ? FText::FromString(FString::Join(Methods, TEXT(", "))) : FText();
}

#undef LOCTEXT_NAMESPACE