#ifndef __FATFS_H
#define __FATFS_H

#include "../Drivers/HDD-ATA.h"
#include "../Include/types.h"
#include "../Memory/MemoryManagement.h"
#include "../Include/Public_VAR.h"
#include "../kernel/MultiTask.h"
#include "../loaders/JD1618.h"
#include "../Structures/list.h"

struct Program
{
    uint8_t name[8];
    uint32_t size;
    uint32_t data;
    void entrypoint();
} __attribute__((packed));

struct BiosParameterBlock32
{
    uint8_t jump[3];
    uint8_t softName[8];
    uint16_t bytesPerSector;
    uint8_t sectorsPerCluster;
    uint16_t reservedSectors;
    uint8_t fatCopies;
    uint16_t rootDirEntries;
    uint16_t totalSectors;
    uint8_t mediaType;
    uint16_t fatSectorCount;
    uint16_t sectorsPerTrack;
    uint16_t headCount;
    uint32_t hiddenSectors;
    uint32_t totalSectorCount;

    uint32_t tableSize;
    uint16_t extFlags;
    uint16_t fatVersion;
    uint32_t rootCluster;
    uint16_t fatInfo;
    uint16_t backupSector;
    uint8_t reserved0[12];
    uint8_t driveNumber;
    uint8_t reserved;
    uint8_t bootSignature;
    uint32_t volumeId;
    uint8_t volumeLabel[11];
    uint8_t fatTypeLabel[8];
} __attribute__((packed));

struct DirectoryEntryFat32
{
    uint8_t name[8];
    uint8_t ext[3];
    uint8_t attributes;
    uint8_t reserved;
    uint8_t cTimeTenth;
    uint16_t cTime;
    uint16_t cDate;
    uint16_t aTime;
    uint16_t firstClusterHi;
    uint16_t wTime;
    uint16_t wDate;
    uint16_t firstClusterLow;
    uint32_t size;
} __attribute__((packed));


void ReadBiosBlock(AdvancedTechnologyAttachment *hd, uint32_t partitionOffset);
void ExecutePRG(char* name,char* EXT, AdvancedTechnologyAttachment *hd);
void listFiles(AdvancedTechnologyAttachment *HDD);

#endif