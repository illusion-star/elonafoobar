locale {
    damage {
        miss {
            ally = "${aln(_2)}${name(_1)}の攻撃を避けた。"
            other = "${aln(_1)}攻撃をかわされた。"
        }
        evade {
            ally = "${aln(_2)}${name(_1)}の攻撃を華麗に避けた。"
            other = "${aln(_1)}攻撃を華麗にかわされた。"
        }
        furthermore = "さらに"

        is_frightened = "${name(_1)}は怖気づいた。"
        critical = "会心の一撃！ "

        wields_proudly = "${name(_1)}は${_2}を誇らしげに構えた。"

        is_healed = "${name(_1)}は回復した。"
        lay_hand = "${name(_1)}は叫んだ。「この者にジュアの加護を。レイハンド！」"

        runs_away_in_terror = "${name(_1)}は恐怖して逃げ出した。"
        sleep_is_disturbed = "${name(_1)}は眠りを妨げられた。"

        explode_click = " *カチッ* "
        splits = "${name(_1)}は分裂した！"
        is_engulfed_in_fury = "${name(_1)}は怒りに体を奮わせた！"

        you_feel_sad = "あなたは悲しくなった。"
        get_off_corpse = "${you()}は${name(_1)}の死体から降りた。"
        death_word_breaks = "死の宣告は無効になった。"

        magic_reaction_hurts = "マナの反動が${name(_1)}の精神を蝕んだ！"

        weapon {
            attacks_with = "${aln(_1)}${name(_2)}に${_3}で${_4}。"
            attacks_and = "${aln(_1)}${name(_2)}を${_3}"

            attacks_unarmed = "${aln(_1)}${name(_2)}に${_3}"
            attacks_unarmed_and = "${aln(_1)}${name(_2)}を${_3}"

            and = ""

            _108 {
                name = "弓"
                verb_and = "撃たれた"
                verb = "射撃し"
            }
            _109 {
                name = "クロスボウ"
                verb_and = "撃たれた"
                verb = "射撃し"
            }
            _110 {
                name = "銃"
                verb_and = "撃たれた"
                verb = "射撃し"
            }
            _100 {
                name = "長剣"
                verb_and = "切り払い"
                verb = "切られた"
            }
            _104 {
                name = "槍"
                verb_and = "突き刺して"
                verb = "刺された"
            }
            _101 {
                name = "短剣"
                verb_and = "突き刺して"
                verb = "刺された"
            }
            _105 {
                name = "杖"
                verb_and = "打って"
                verb = "打たれた"
            }
            _103 {
                name = "鈍器"
                verb_and = "打って"
                verb = "打たれた"
            }
            _102 {
                name = "斧"
                verb_and = "切り払い"
                verb = "切られた"
            }
            _107 {
                name = "鎌"
                verb_and = "切り払い"
                verb = "切られた"
            }
            _111 {
                # name is automatically set based on thrown item name
                verb_and = "投げ"
                verb = "攻撃された"
            }
        }

        reactive_attack {
            thorns = "棘が${name(_1)}に刺さった。"
            ether_thorns = "エーテルの棘が${name(_1)}に刺さった。"
            acids = "酸が飛び散った。"
        }

        levels {
            scratch = "かすり傷をつけた。"
            slightly = "軽い傷を負わせた。"
            moderately = "傷つけた。"
            severely = "深い傷を負わせた。"
            critically = "致命傷を与えた。"
        }

        reactions {
            screams = "${name(_1)}は痛手を負った。"
            writhes_in_pain = "${name(_1)}は苦痛にもだえた。"
            is_severely_hurt = "${name(_1)}は悲痛な叫び声をあげた。"
        }

        element {
            default = "は傷ついた。"
            _50 = "${name(_1)}は燃え上がった。"
            _51 = "${name(_1)}は凍えた。"
            _52 = "${name(_1)}に電流が走った。"
            _53 = "${name(_1)}は闇の力で傷ついた。"
            _54 = "${name(_1)}は狂気に襲われた。"
            _55 = "${name(_1)}は吐き気を催した。"
            _56 = "${name(_1)}は冥界の冷気で傷ついた。"
            _57 = "${name(_1)}は轟音の衝撃を受けた。"
            _58 = "${name(_1)}の神経は傷ついた。"
            _59 = "${name(_1)}は混沌の渦で傷ついた。"
            # _60
            _61 = "${name(_1)}は切り傷を負った。"
            # _62
            _63 = "${name(_1)}は酸に焼かれた。"
        }

        sand_bag {
            _0 = "「くっ！」"
            _1 = "「まだまだ！」"
            _2 = "「もう限界…」"
            _3 = "「うぐぐ」"
            _4 = "「あう」"
            _5 = "「ああんっ」"
        }
    }
}
