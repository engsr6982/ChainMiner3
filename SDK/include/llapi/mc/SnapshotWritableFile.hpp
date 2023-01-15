/**
 * @file  SnapshotWritableFile.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class SnapshotWritableFile.
 *
 */
class SnapshotWritableFile {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SNAPSHOTWRITABLEFILE
public:
    class SnapshotWritableFile& operator=(class SnapshotWritableFile const &) = delete;
    SnapshotWritableFile(class SnapshotWritableFile const &) = delete;
    SnapshotWritableFile() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -772046486
     */
    virtual ~SnapshotWritableFile();
    /**
     * @vftbl  1
     * @symbol ?Append@SnapshotWritableFile@@UEAA?AVStatus@leveldb@@AEBVSlice@3@@Z
     * @hash   1588759211
     */
    virtual class leveldb::Status Append(class leveldb::Slice const &);
    /**
     * @vftbl  2
     * @symbol ?Close@SnapshotWritableFile@@UEAA?AVStatus@leveldb@@XZ
     * @hash   -259267372
     */
    virtual class leveldb::Status Close();
    /**
     * @vftbl  3
     * @symbol ?Flush@SnapshotWritableFile@@UEAA?AVStatus@leveldb@@XZ
     * @hash   1557995984
     */
    virtual class leveldb::Status Flush();
    /**
     * @vftbl  4
     * @symbol ?Sync@SnapshotWritableFile@@UEAA?AVStatus@leveldb@@XZ
     * @hash   213464375
     */
    virtual class leveldb::Status Sync();
    /**
     * @symbol ??0SnapshotWritableFile@@QEAA@$$QEAPEAVWritableFile@leveldb@@AEAVshared_mutex@std@@@Z
     * @hash   -1989487568
     */
    MCAPI SnapshotWritableFile(class leveldb::WritableFile *&&, class std::shared_mutex &);

};