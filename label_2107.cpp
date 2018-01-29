#include "elona.hpp"
#include "variables.hpp"


namespace elona
{
int label_2107()
{
    notesel(filemod);
    gdata(805) = gdata(805) + timeGetTime() / 1000 - time_begin;
    time_begin = timeGetTime() / 1000;
    if (fmode == 8 || fmode == 7) {
        folder = exedir + u8"save\\"s + playerid + u8"\\"s;
        if (fmode == 8) { fread = 0; }
        if (fmode == 7) { fread = 1; }
        if (fmode == 8) {
            playerheader = ""s + cdatan(0, 0) + u8" Lv:"s + cdata(38, 0) +
                u8" "s + mdatan(0);
            bsave(folder + u8"header.txt"s, playerheader);
        }
        {
            int cnt = 0;
            for (int cnt_end = cnt + (15); cnt < cnt_end; ++cnt) {
                file = folder;
                if (cnt == 0) {
                    file += u8"gdata.s1"s;
                    fsize = 4000;
                }
                if (cnt == 1) {
                    file += u8"cdata.s1"s;
                    fsize = 114000;
                }
                if (cnt == 2) {
                    file += u8"sdata.s1"s;
                    fsize = 273600;
                }
                if (cnt == 3) {
                    file += u8"spell.s1"s;
                    fsize = 800;
                }
                if (cnt == 4) {
                    file += u8"inv.s1"s;
                    fsize = 369600;
                }
                if (cnt == 5) {
                    file += u8"kitem.s1"s;
                    fsize = 9600;
                }
                if (cnt == 6) {
                    file += u8"knpc.s1"s;
                    fsize = 6400;
                }
                if (cnt == 7) {
                    file += u8"adata.s1"s;
                    fsize = 80000;
                }
                if (cnt == 8) {
                    file += u8"spact.s1"s;
                    fsize = 2000;
                }
                if (cnt == 9) {
                    file += u8"qdata.s1"s;
                    fsize = 40000;
                }
                if (cnt == 10) {
                    file += u8"mat.s1"s;
                    fsize = 1600;
                }
                if (cnt == 11) {
                    file += u8"trait.s1"s;
                    fsize = 2000;
                }
                if (cnt == 12) {
                    file += u8"pcc.s1"s;
                    fsize = 2400;
                }
                if (cnt == 13) {
                    file += u8"card.s1"s;
                    fsize = 16000;
                }
                if (cnt == 14) {
                    file += u8"krecipe.s1"s;
                    fsize = 4800;
                }
                if (fread == 1) {
                    exist(file);
                    if (strsize == -1) { continue; }
                }
                if (fread == 0) { zOpen(hgz, file, 1, 3); }
                if (fread == 1) { zOpen(hgz, file, 0); }
                if (cnt == 0) {
                    if (fread == 0) { zWrite(gdata, hgz, fsize); }
                    if (fread == 1) { zRead(gdata, hgz, fsize); }
                }
                if (cnt == 1) {
                    if (fread == 0) { zWrite(cdata, hgz, fsize); }
                    if (fread == 1) { zRead(cdata, hgz, fsize); }
                }
                if (cnt == 2) {
                    if (fread == 0) { zWrite(sdata, hgz, fsize); }
                    if (fread == 1) { zRead(sdata, hgz, fsize); }
                }
                if (cnt == 3) {
                    if (fread == 0) { zWrite(spell, hgz, fsize); }
                    if (fread == 1) { zRead(spell, hgz, fsize); }
                }
                if (cnt == 4) {
                    if (fread == 0) { zWrite(inv, hgz, fsize); }
                    if (fread == 1) { zRead(inv, hgz, fsize); }
                }
                if (cnt == 5) {
                    if (fread == 0) { zWrite(itemmemory, hgz, fsize); }
                    if (fread == 1) { zRead(itemmemory, hgz, fsize); }
                }
                if (cnt == 6) {
                    if (fread == 0) { zWrite(npcmemory, hgz, fsize); }
                    if (fread == 1) { zRead(npcmemory, hgz, fsize); }
                }
                if (cnt == 7) {
                    if (fread == 0) { zWrite(adata, hgz, fsize); }
                    if (fread == 1) { zRead(adata, hgz, fsize); }
                }
                if (cnt == 8) {
                    if (fread == 0) { zWrite(spact, hgz, fsize); }
                    if (fread == 1) { zRead(spact, hgz, fsize); }
                }
                if (cnt == 9) {
                    if (fread == 0) { zWrite(qdata, hgz, fsize); }
                    if (fread == 1) { zRead(qdata, hgz, fsize); }
                }
                if (cnt == 10) {
                    if (fread == 0) { zWrite(mat, hgz, fsize); }
                    if (fread == 1) { zRead(mat, hgz, fsize); }
                }
                if (cnt == 11) {
                    if (fread == 0) { zWrite(trait, hgz, fsize); }
                    if (fread == 1) { zRead(trait, hgz, fsize); }
                }
                if (cnt == 12) {
                    if (fread == 0) { zWrite(pcc, hgz, fsize); }
                    if (fread == 1) { zRead(pcc, hgz, fsize); }
                }
                if (cnt == 13) {
                    if (fread == 0) { zWrite(card, hgz, fsize); }
                    if (fread == 1) { zRead(card, hgz, fsize); }
                }
                if (cnt == 14) {
                    if (fread == 0) { zWrite(recipememory, hgz, fsize); }
                    if (fread == 1) {
                        if (gdata(96) >= 1200) {
                            zRead(recipememory, hgz, fsize);
                        }
                    }
                }
                zClose(hgz);
            }
        }
        file = folder + u8"art.log"s;
        notesel(artifactlocation);
        if (fread == 0) { notesave(file); }
        if (fread == 1) { noteload(file); }
        file = folder + u8"news.log"s;
        notesel(newsbuff);
        if (fread == 0) { notesave(file); }
        if (fread == 1) { noteload(file); }
        file = folder + u8"cdatan.s1"s;
        fmode = u8"cdatan1"s;
        arrayfile();
        file = folder + u8"qname.s1"s;
        fmode = u8"qname"s;
        arrayfile();
        file = folder + u8"gdatan.s1"s;
        fmode = u8"gdatan"s;
        arrayfile();
        if (fread == 0) {
            bsave(folder + u8"evnum.s1"s, evnum);
            bsave(folder + u8"evdata1.s1"s, evdata1);
            bsave(folder + u8"evdata2.s1"s, evdata2);
            bsave(folder + u8"evlist.s1"s, evlist);
        } else {
            exist(folder + u8"evnum.s1"s);
            if (strsize != -1) { bload(folder + u8"evnum.s1"s, evnum); }
            exist(folder + u8"evdata1.s1"s);
            if (strsize != -1) { bload(folder + u8"evdata1.s1"s, evdata1); }
            exist(folder + u8"evdata2.s1"s);
            if (strsize != -1) { bload(folder + u8"evdata2.s1"s, evdata2); }
            exist(folder + u8"evlist.s1"s);
            if (strsize != -1) { bload(folder + u8"evlist.s1"s, evlist); }
        }
    }
    if (fmode == 14 || fmode == 15) {
        if (fmode == 14) {
            fread = 0;
            folder = exedir + u8"tmp\\"s;
        }
        if (fmode == 15) {
            fread = 1;
            folder = exedir + u8"save\\"s + geneuse + u8"\\"s;
        }
        if (fmode == 14) {
            playerheader =
                ""s + cdatan(0, 0) + u8"(Lv"s + cdata(38, 0) + u8")の遺伝子"s;
            file = folder + u8"gene_header.txt"s;
            bsave(file, playerheader);
            fileadd(file);
        }
        {
            int cnt = 0;
            for (int cnt_end = cnt + (9); cnt < cnt_end; ++cnt) {
                file = folder;
                if (cnt == 0) {
                    file += u8"gene.s1"s;
                    fsize = 400;
                }
                if (cnt == 1) {
                    file += u8"g_cdata.s1"s;
                    fsize = 114000;
                }
                if (cnt == 2) {
                    file += u8"g_sdata.s1"s;
                    fsize = 273600;
                }
                if (cnt == 3) {
                    file += u8"g_spell.s1"s;
                    fsize = 800;
                }
                if (cnt == 4) {
                    file += u8"g_inv.s1"s;
                    fsize = 369600;
                }
                if (cnt == 5) {
                    file += u8"g_spact.s1"s;
                    fsize = 2000;
                }
                if (cnt == 6) {
                    file += u8"g_mat.s1"s;
                    fsize = 1600;
                }
                if (cnt == 7) {
                    file += u8"g_card.s1"s;
                    fsize = 16000;
                }
                if (cnt == 8) {
                    file += u8"g_genetemp.s1"s;
                    fsize = 4000;
                }
                if (fread == 1) {
                    exist(file);
                    if (strsize == -1) { continue; }
                }
                if (fread == 0) {
                    zOpen(hgz, file, 1, 3);
                    fileadd(""s + file);
                }
                if (fread == 1) { zOpen(hgz, file, 0); }
                if (cnt == 0) {}
                if (cnt == 1) {
                    if (fread == 0) { zWrite(cdata, hgz, fsize); }
                    if (fread == 1) { zRead(cdata, hgz, fsize); }
                }
                if (cnt == 2) {
                    if (fread == 0) { zWrite(sdata, hgz, fsize); }
                    if (fread == 1) { zRead(sdata, hgz, fsize); }
                }
                if (cnt == 3) {
                    if (fread == 0) { zWrite(spell, hgz, fsize); }
                    if (fread == 1) { zRead(spell, hgz, fsize); }
                }
                if (cnt == 4) {
                    if (fread == 0) { zWrite(inv, hgz, fsize); }
                    if (fread == 1) { zRead(inv, hgz, fsize); }
                }
                if (cnt == 5) {
                    if (fread == 0) { zWrite(spact, hgz, fsize); }
                    if (fread == 1) { zRead(spact, hgz, fsize); }
                }
                if (cnt == 6) {
                    if (fread == 0) { zWrite(mat, hgz, fsize); }
                    if (fread == 1) { zRead(mat, hgz, fsize); }
                }
                if (cnt == 7) {
                    if (fread == 0) { zWrite(card, hgz, fsize); }
                    if (fread == 1) { zRead(card, hgz, fsize); }
                }
                if (cnt == 8) {
                    if (fread == 0) { zWrite(gdata, hgz, fsize); }
                    if (fread == 1) { zRead(genetemp, hgz, fsize); }
                }
                zClose(hgz);
            }
        }
    }
    if (fmode == 2 || fmode == 1) {
        folder = exedir + u8"tmp\\"s;
        if (fmode == 2) { fread = 0; }
        if (fmode == 1) { fread = 1; }
        {
            int cnt = 0;
            for (int cnt_end = cnt + (5); cnt < cnt_end; ++cnt) {
                file = folder;
                if (cnt == 0) {
                    file += u8"mdata_"s + mid + u8".s2"s;
                    fsize = 400;
                }
                if (cnt == 1) {
                    if (fread == 1) {
                        DIM4(map, mdata(0), mdata(1), 10);
                        DIM3(mapsync, mdata(0), mdata(1));
                        DIM3(mef, 9, 200);
                    }
                    file += u8"map_"s + mid + u8".s2"s;
                    fsize = mdata(0) * mdata(1) * 10 * 4;
                }
                if (cnt == 2) {
                    file += u8"cdata_"s + mid + u8".s2"s;
                    fsize = 376000;
                }
                if (cnt == 3) {
                    file += u8"sdata_"s + mid + u8".s2"s;
                    fsize = 902400;
                }
                if (cnt == 4) {
                    if (fread) {
                        if (mdata(21) == 0) {
                            {
                                int cnt = 0;
                                for (int cnt_end = cnt + (mdata(1));
                                     cnt < cnt_end; ++cnt) {
                                    cnt2 = cnt;
                                    {
                                        int cnt = 0;
                                        for (int cnt_end = cnt + (mdata(0));
                                             cnt < cnt_end; ++cnt) {
                                            map(cnt, cnt2, 8) = 0;
                                        }
                                    }
                                }
                            }
                            mdata(21) = 1;
                            continue;
                        }
                    }
                    file += u8"mef_"s + mid + u8".s2"s;
                    fsize = 7200;
                }
                if (fread == 0) {
                    zOpen(hgz, file, 1, 3);
                    fileadd(""s + file);
                }
                if (fread == 1) { zOpen(hgz, file, 0); }
                if (cnt == 0) {
                    if (fread == 0) { zWrite(mdata, hgz, fsize); }
                    if (fread == 1) { zRead(mdata, hgz, fsize); }
                }
                if (cnt == 1) {
                    if (fread == 0) { zWrite(map, hgz, fsize); }
                    if (fread == 1) { zRead(map, hgz, fsize); }
                }
                if (cnt == 2) {
                    if (fread == 0) { zWrite(cdata, hgz, fsize, 57); }
                    if (fread == 1) { zRead(cdata, hgz, fsize, 57); }
                }
                if (cnt == 3) {
                    if (fread == 0) { zWrite(sdata, hgz, fsize, 57); }
                    if (fread == 1) { zRead(sdata, hgz, fsize, 57); }
                }
                if (cnt == 4) {
                    if (fread == 0) { zWrite(mef, hgz, fsize); }
                    if (fread == 1) { zRead(mef, hgz, fsize); }
                }
                zClose(hgz);
            }
        }
        file = folder + u8"cdatan_"s + mid + u8".s2"s;
        fmode = u8"cdatan2"s;
        arrayfile();
        file = folder + u8"mdatan_"s + mid + u8".s2"s;
        fmode = u8"mdatan"s;
        arrayfile();
    }
    if (fmode == 20 || fmode == 19) {
        folder = exedir + u8"user\\"s;
        if (fmode == 20) { fread = 0; }
        if (fmode == 19) { fread = 1; }
        {
            int cnt = 0;
            for (int cnt_end = cnt + (3); cnt < cnt_end; ++cnt) {
                file = folder;
                if (cnt == 0) {
                    file += u8"m1_"s + id + u8".t"s;
                    fsize = 400;
                }
                if (cnt == 1) {
                    if (fread == 1) {
                        DIM4(map, mdata(0), mdata(1), 10);
                        DIM3(mapsync, mdata(0), mdata(1));
                        DIM3(mef, 9, 200);
                    }
                    file += u8"m2_"s + id + u8".t"s;
                    fsize = mdata(0) * mdata(1) * 10 * 4;
                }
                if (cnt == 2) {
                    file += u8"m3_"s + id + u8".t"s;
                    fsize = 1164800;
                }
                if (fread == 0) { zOpen(hgz, file, 1, 3); }
                if (fread == 1) { zOpen(hgz, file, 0); }
                if (cnt == 0) {
                    if (fread == 0) { zWrite(mdata, hgz, fsize); }
                    if (fread == 1) { zRead(mdata, hgz, fsize); }
                }
                if (cnt == 1) {
                    if (fread == 0) { zWrite(map, hgz, fsize); }
                    if (fread == 1) { zRead(map, hgz, fsize); }
                }
                if (cnt == 2) {
                    if (fread == 0) { zWrite(inv, hgz, fsize, 1320); }
                    if (fread == 1) { zRead(inv, hgz, fsize, 1320); }
                }
                zClose(hgz);
            }
        }
        file = folder + u8"m4_"s + id + u8".t"s;
        fmode = u8"mdatan"s;
        elona_export = 1;
        arrayfile();
        if (fread == 0) {
            zipadd(u8"m1_"s + id + u8".t"s);
            zipadd(u8"m2_"s + id + u8".t"s);
            zipadd(u8"m3_"s + id + u8".t"s);
            zipadd(u8"m4_"s + id + u8".t"s);
        }
    }
    if (fmode == 22 || fmode == 21) {
        folder = exedir + u8"user\\"s;
        if (fmode == 22) {
            fread = 0;
            tg = 1;
        }
        if (fmode == 21) {
            fread = 1;
            tg = 0;
        }
        enemyteam = -1;
        gdata(86) = 0;
        SDIM1(untaglist);
        {
            int cnt = 0;
            for (int cnt_end = cnt + (245); cnt < cnt_end; ++cnt) {
                if (fread == 0) {
                    if (list(0, cnt) == 0) { continue; }
                    tg = cnt;
                } else {
                    exist(folder + u8"c1_"s + id + u8".t"s);
                    if (strsize == -1) { break; }
                    tg = 0;
                    {
                        int cnt = 57;
                        for (int cnt_end = cnt + (188); cnt < cnt_end; ++cnt) {
                            if (cdata(0, cnt) == 0) {
                                tg = cnt;
                                break;
                            }
                        }
                    }
                    if (tg == 0) { break; }
                }
                {
                    int cnt = 0;
                    for (int cnt_end = cnt + (3); cnt < cnt_end; ++cnt) {
                        file = folder;
                        if (cnt == 0) {
                            file += u8"c1_"s + id + u8".t"s;
                            fsize = 2000;
                        }
                        if (cnt == 1) {
                            file += u8"c2_"s + id + u8".t"s;
                            fsize = 4800;
                        }
                        if (cnt == 2) {
                            file += u8"c3_"s + id + u8".t"s;
                            inv_getheader(tg);
                            fsize = 280 * invrange;
                        }
                        if (fread == 0) { zOpen(hgz, file, 1, 3); }
                        if (fread == 1) { zOpen(hgz, file, 0); }
                        if (cnt == 0) {
                            if (fread == 0) { zWrite(cdata, hgz, fsize, tg); }
                            if (fread == 1) { zRead(cdata, hgz, fsize, tg); }
                        }
                        if (cnt == 1) {
                            if (fread == 0) { zWrite(sdata, hgz, fsize, tg); }
                            if (fread == 1) { zRead(sdata, hgz, fsize, tg); }
                        }
                        if (cnt == 2) {
                            if (fread == 0) {
                                zWrite(inv, hgz, fsize, invhead);
                            }
                            if (fread == 1) { zRead(inv, hgz, fsize, invhead); }
                        }
                        zClose(hgz);
                    }
                }
                file = folder + u8"c4_"s + id + u8".t"s;
                fmode = u8"cdatan3"s;
                elona_export = 1;
                arrayfile();
                if (fread == 0) {
                    zipadd(u8"c1_"s + id + u8".t"s);
                    zipadd(u8"c2_"s + id + u8".t"s);
                    zipadd(u8"c3_"s + id + u8".t"s);
                    zipadd(u8"c4_"s + id + u8".t"s);
                    if (cdata(27, tg) == 343) {
                        exist(folder + userdatan(6, cdata(157, tg)));
                        if (strsize != -1) {
                            if (cdata(157, tg) != usernpcmax) {
                                if (instr(untaglist, 0,
                                        u8"/"s + userdatan(0, cdata(157, tg)) +
                                            u8"/"s) == -1) {
                                    if (gdata(86) < 10) {
                                        bcopy(folder +
                                                userdatan(6, cdata(157, tg)),
                                            folder + u8"_tmp_"s + gdata(86) +
                                                u8".npc"s);
                                        zipadd(
                                            u8"_tmp_"s + gdata(86) + u8".npc"s);
                                        untaglist += u8"/"s +
                                            userdatan(0, cdata(157, tg)) +
                                            u8"/"s;
                                        ++gdata(86);
                                    }
                                }
                            }
                        }
                    }
                } else {
                    inv_getheader(tg);
                    {
                        int cnt = invhead;
                        for (int cnt_end = cnt + (invrange); cnt < cnt_end;
                             ++cnt) {
                            inv(18, cnt) = 0;
                        }
                    }
                    {
                        int cnt = 100;
                        for (int cnt_end = cnt + (30); cnt < cnt_end; ++cnt) {
                            cdata(cnt, tg) = cdata(cnt, tg) / 10000 * 10000;
                        }
                    }
                    rc = tg;
                    label_2666();
                    cdata(12, rc) = 0;
                    rowactend(rc);
                    cbitmod(967, rc, 0);
                    cbitmod(968, rc, 0);
                    cdata(50, rc) = cdata(51, rc);
                    cdata(55, rc) = cdata(56, rc);
                    cbitmod(960, rc, 0);
                    cbitmod(989, tc, 0);
                    if (importmode == 0) {
                        cdata(150, tg) = 20;
                        cdata(30, tg) = 0;
                        if (cdata(9, tg) >= 10) {
                            if (userrelation == 0) {
                                cdata(9, tg) = 0;
                                cdata(69, tg) = 0;
                            } else {
                                cdata(9, tg) = -3;
                                cdata(69, tg) = -3;
                            }
                        }
                        cxinit = cdata(1, tg);
                        cyinit = cdata(2, tg);
                        label_1532();
                    }
                    if (importmode == 1) {
                        if (enemyteam == -1) { enemyteam = rc; }
                        cdata(9, rc) = -3;
                        cdata(69, rc) = -3;
                        map_placearena(rc, 1);
                    }
                }
                ++id;
            }
        }
    }
    if (fmode == 16) {
        DIM3(cmapdata, 5, 400);
        {
            int cnt = 0;
            for (int cnt_end = cnt + (2); cnt < cnt_end; ++cnt) {
                if (cnt == 0) {
                    file = fmapfile + u8".map"s;
                    fsize = mdata(0) * mdata(1) * 3 * 4;
                }
                if (cnt == 1) {
                    file = fmapfile + u8".obj"s;
                    fsize = 8000;
                }
                if (cnt == 1) {
                    exist(file);
                    if (strsize == -1) { continue; }
                }
                zOpen(hgz, file, 0);
                if (cnt == 0) { zRead(map, hgz, fsize); }
                if (cnt == 1) { zRead(cmapdata, hgz, fsize); }
                zClose(hgz);
            }
        }
    }
    if (fmode == 6 || fmode == 5) {
        if (fmode == 6) { fread = 0; }
        if (fmode == 5) {
            fread = 1;
            DIM3(cmapdata, 5, 400);
        }
        {
            int cnt = 0;
            for (int cnt_end = cnt + (3); cnt < cnt_end; ++cnt) {
                if (cnt == 0) {
                    file = fmapfile + u8".idx"s;
                    fsize = 400;
                }
                if (cnt == 1) {
                    if (fread == 1) {
                        DIM4(map, mdata(0), mdata(1), 10);
                        DIM3(mapsync, mdata(0), mdata(1));
                        DIM3(mef, 9, 200);
                    }
                    file = fmapfile + u8".map"s;
                    fsize = mdata(0) * mdata(1) * 10 * 4;
                }
                if (cnt == 2) {
                    file = fmapfile + u8".obj"s;
                    fsize = 8000;
                }
                if (cnt == 2 && fread == 1) {
                    exist(file);
                    if (strsize == -1) { continue; }
                }
                if (fread == 0) { zOpen(hgz, file, 1, 3); }
                if (fread == 1) { zOpen(hgz, file, 0); }
                if (cnt == 0) {
                    if (fread == 0) { zWrite(mdata, hgz, fsize); }
                    if (fread == 1) {
                        zRead(mdatatmp, hgz, fsize);
                        {
                            int cnt = 0;
                            for (int cnt_end = cnt + (5); cnt < cnt_end;
                                 ++cnt) {
                                mdata(cnt) = mdatatmp(cnt);
                            }
                        }
                    }
                }
                if (cnt == 1) {
                    if (fread == 0) { zWrite(map, hgz, fsize); }
                    if (fread == 1) { zRead(map, hgz, fsize); }
                }
                if (cnt == 2) {
                    if (fread == 0) { zWrite(cmapdata, hgz, fsize); }
                    if (fread == 1) { zRead(cmapdata, hgz, fsize); }
                }
                zClose(hgz);
            }
        }
    }
    if (fmode == 4 || fmode == 3) {
        folder = exedir + u8"tmp\\"s;
        if (fmode == 4) { fread = 0; }
        if (fmode == 3) { fread = 1; }
        file = folder + file;
        fsize = 1164800;
        if (fread == 0) {
            zOpen(hgz, file, 1, 3);
            fileadd(file);
        }
        if (fread == 1) { zOpen(hgz, file, 0); }
        if (fread == 0) { zWrite(inv, hgz, fsize, 1320); }
        if (fread == 1) { zRead(inv, hgz, fsize, 1320); }
        zClose(hgz);
    }
    if (fmode == 23 || fmode == 24) {
        if (fmode == 23) { fread = 0; }
        if (fmode == 24) { fread = 1; }
        fsize = 4000;
        if (fread == 0) {
            zOpen(hgz, file, 1, 3);
            fileadd(""s + file);
        }
        if (fread == 1) { zOpen(hgz, file, 0); }
        if (fread == 0) { zWrite(deck, hgz, fsize); }
        if (fread == 1) { zRead(deck, hgz, fsize); }
        zClose(hgz);
    }
    if (fmode == 18 || fmode == 17) {
        folder = exedir + u8"tmp\\"s;
        if (fmode == 18) { fread = 0; }
        if (fmode == 17) { fread = 1; }
        exist(file + u8"cdata_"s + mid + u8".s2"s);
        if (strsize == -1) {
            stat = 0;
            return stat;
        }
        {
            int cnt = 0;
            for (int cnt_end = cnt + (5); cnt < cnt_end; ++cnt) {
                file = folder;
                if (cnt == 0) {
                    file += u8"cdata_"s + mid + u8".s2"s;
                    fsize = 376000;
                }
                if (cnt == 1) {
                    file += u8"sdata_"s + mid + u8".s2"s;
                    fsize = 902400;
                }
                if (fread == 0) {
                    zOpen(hgz, file, 1, 3);
                    fileadd(""s + file);
                }
                if (fread == 1) { zOpen(hgz, file, 0); }
                if (cnt == 0) {
                    if (fread == 0) { zWrite(cdata, hgz, fsize, 57); }
                    if (fread == 1) { zRead(cdata, hgz, fsize, 57); }
                }
                if (cnt == 1) {
                    if (fread == 0) { zWrite(sdata, hgz, fsize, 57); }
                    if (fread == 1) { zRead(sdata, hgz, fsize, 57); }
                }
                zClose(hgz);
            }
        }
        file = folder + u8"cdatan_"s + mid + u8".s2"s;
        fmode = u8"cdatan2"s;
        arrayfile();
    }
    if (fmode == 10) {
        dirlist(buff, exedir + u8"tmp\\*.*"s);
        if (stat == 0) {
            stat = stat;
            return stat;
        }
        notesel(buff);
        {
            int cnt = 0;
            for (int cnt_end = cnt + (stat); cnt < cnt_end; ++cnt) {
                noteget(file, cnt);
                file = exedir + u8"tmp\\"s + file;
                exist(file);
                if (strsize != -1) { elona_delete(file); }
            }
        }
    }
    if (fmode == 9) {
        folder = exedir + u8"save\\"s + playerid;
        dirlist(buff, folder + u8"\\*.*"s);
        if (stat != 0) {
            notesel(buff);
            {
                int cnt = 0;
                for (int cnt_end = cnt + (stat); cnt < cnt_end; ++cnt) {
                    noteget(file, cnt);
                    elona_delete(folder + u8"\\"s + file);
                }
            }
        }
        RemoveDirectoryA(folder);
    }
    if (fmode == 11 || fmode == 12) {
        if (fmode == 12) {
            exist(exedir + u8"tmp\\mdata_"s + mid + u8".s2"s);
            if (strsize == -1) {
                stat = 0;
                return stat;
            }
        }
        file = exedir + u8"tmp\\map_"s + mid + u8".s2"s;
        exist(file);
        if (strsize == -1) {
            stat = 0;
            return stat;
        }
        elona_delete(file);
        fileadd(file, 1);
        if (fmode == 11) {
            file = exedir + u8"tmp\\cdata_"s + mid + u8".s2"s;
            elona_delete(file);
            fileadd(file, 1);
            file = exedir + u8"tmp\\sdata_"s + mid + u8".s2"s;
            elona_delete(file);
            fileadd(file, 1);
            file = exedir + u8"tmp\\cdatan_"s + mid + u8".s2"s;
            elona_delete(file);
            fileadd(file, 1);
            file = exedir + u8"tmp\\inv_"s + mid + u8".s2"s;
            elona_delete(file);
            fileadd(file, 1);
        }
        file = exedir + u8"tmp\\mdata_"s + mid + u8".s2"s;
        elona_delete(file);
        fileadd(file, 1);
        file = exedir + u8"tmp\\mdatan_"s + mid + u8".s2"s;
        elona_delete(file);
        fileadd(file, 1);
        file = exedir + u8"tmp\\mef_"s + mid + u8".s2"s;
        elona_delete(file);
        fileadd(file, 1);
    }
    if (fmode == 13) {
        {
            int cnt = 0;
            for (int cnt_end = cnt + (40); cnt < cnt_end; ++cnt) {
                adata(cnt, area) = 0;
            }
        }
        folder = exedir + u8"tmp"s;
        dirlist(buff, folder + u8"\\*_"s + area + u8"_*.*"s);
        if (stat != 0) {
            notesel(buff);
            {
                int cnt = 0;
                for (int cnt_end = cnt + (stat); cnt < cnt_end; ++cnt) {
                    noteget(file, cnt);
                    file = folder + u8"\\"s + file;
                    elona_delete(file);
                    fileadd(file, 1);
                }
            }
        }
    }
    stat = 0;
    return stat;
}


} // namespace elona