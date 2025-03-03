import subprocess

def run_test(input_str):
    try:
        result = subprocess.run(['./PmergeMe', input_str], capture_output=True, text=True)
        print("="*40)
        print(f"Input: {input_str}")
        print("-"*40)
        print("Output:")
        print(result.stdout.strip())
        if result.stderr:
            print("Errors:")
            print(result.stderr.strip())
        print("="*40)
    except Exception as e:
        print(f"An error occurred: {e}")

def main():
    test_inputs = [
        "8 9 10 11 12 13 14 15 1 2 3 4 5 6 7",
        "1 2 3",
        "-1",
        "",
        "100 7 42 45",
        "100 7 42 45 100",
        "1 1 1 1",
        "39 59 69 58 72 84 72 77 48 58 76 61 69 16 19 10 79 62 25 6 96 10 52 73 61 32 31 5 60 95 90 44 99 7 29 24 71 72 43 93 34 66 23 4 54 59 24 100 5 38",
        "103 163 443 45 294 229 465 62 194 371 136 128 318 178 332 233 207 458 362 493 51 251 46 420 447 228 266 236 83 120 200 109 203 88 97 230 236 408 499 22 493 86 307 148 70 68 299 243 231 435 358 490 412 33 278 325 448 466 426 69 379 65 95 484 213 436 57 421 261 206 378 410 115 185 193 331 475 310 54 378 239 44 341 192 120 434 232 288 277 278 318 6 409 455 431 332 75 70 348 342",
        "381 514 710 26 749 511 456 675 795 907 383 192 744 527 739 6 851 203 289 190 360 688 907 200 819 680 536 609 679 982 562 521 331 672 286 356 153 505 842 338 330 332 927 110 957 364 954 837 888 229 387 578 893 847 282 967 888 62 504 577 30 112 292 530 645 423 734 918 917 440 837 547 373 232 382 809 671 908 135 561 768 191 229 87 898 33 411 124 881 171 903 235 966 413 433 306 157 501 35 287 169 710 195 94 925 730 81 90 734 853 666 162 918 55 131 714 154 519 154 450 780 481 677 609 74 973 752 290 695 521 845 936 820 983 455 114 768 656 468 614 899 859 672 128 676 498 546 653 735 674 446 267 162 530 59 133 121 588 449 55 710 380 824 13 398 848 889 790 735 321 567 846 464 57 192 197 954 584 845 307 29 626 541 254 887 337 210 14 944 540 901 921 481 161 385 639 41 154 265 121",
        "856 585 649 1 425 297 666 994 370 187 696 656 308 645 957 704 828 398 438 97 247 46 72 123 915 555 160 773 720 368 537 576 732 429 211 738 625 463 984 18 464 37 388 449 272 960 483 60 46 373 488 642 51 351 941 154 470 621 61 71 867 462 784 265 350 88 995 709 423 869 106 672 189 408 493 874 864 685 505 130 833 490 809 246 868 682 73 837 863 780 782 587 776 732 906 876 649 353 188 734 820 568 720 470 499 33 541 815 545 151 505 414 16 245 287 397 780 367 970 493 59 888 774 146 216 221 971 890 674 53 314 6 682 593 408 6 961 516 824 714 42 655 110 517 870 925 619 753 239 805 515 772 622 693 623 898 766 742 634 148 710 977 750 887 487 384 368 918 623 124 886 409 113 120 270 253 312 691 907 742 59 476 172 933 803 110 497 82 606 934 315 26 484 291 653 3 757 949 587 285 133 448 868 156 984 640 685 421 750 472 665 355 535 205 111 407 760 687 195 130 290 403 18 853 692 768 145 111 796 369 384 180 100 4 668 150 992 883 46 267 77 294 187 904 541 202 610 169 962 926 692 697 67 406 63 487 589 582 648 230 789 334 155 444 627 999 539 829 641 732 322 255 15 326 523 934 984 126 477 280 569 841 30 253 57 763 402 84 260 918 796 491 617 769 929 720 901 955 643 899 533 899 710 72 334 459 661 822 352 543 44 901 573 647 304 59 312 832 698 510 371 946 57 223 266 115 684 957 287 414 965 720 63 719 355 429 491 464 43 521 362 378 240 532 149 371 374 918 489 361 640 988 816 61 394 365 768 327 3 24 3 705 871 714 496 656 45 882 990 138 456 280 256 526 118 51 874 672 355 242 369 551 94 703 446 972 615 705 781 93 989 756 315 532 305 610 827 756 909 864 244 959 911 220 578 441 753 358 669 471 121 68 289 235 553 835 983 834 989 528 396 471 586 130 224 215 790 356 664 121 977 76 769 107 289 760 123 977 180 832 51 156 982 701 140 363 193 922 363 828 952 625 72 129 690 54 748 620 147 233 505 366 778 656 725 747 354 663 644 7 322 728 753 330 558 367 751 600 903 217 316 694 686 155 375 435 531 569 664 432 302 164 551 798 466 709 890 37 227 744",
        "4295 3371 7009 6416 3938 6837 9180 4224 4252 6627 105 5043 9967 4289 503 524 3435 6676 5746 6710 8022 55 5900 6059 4989 9253 3070 396 8262 3926 4893 6508 7768 7920 5089 6951 198 6430 3821 1090 7275 4552 1497 2470 1457 8404 2020 8249 2213 7938 2721 8520 1229 5303 828 4631 7748 1665 7609 1149 2901 5408 7823 1983 5848 571 9200 1731 1396 5871 3278 2824 1618 6233 5125 738 1266 4308 4561 1030 1261 8541 7360 426 3892 3020 6916 3329 1186 7286 3434 7458 8345 2423 1119 9364 649 8725 6320 1323 9443 441 9568 2942 2512 6202 7088 3533 8045 6153 6258 5323 5516 1927 3601 9839 1264 506 986 5941 9427 1733 3242 2534 834 310 1976 6486 6980 4928 3637 2059 9012 8455 3023 5047 3088 2504 2721 4640 703 7210 3015 9738 2933 1617 7029 8257 8290 1943 6741 3454 3199 4911 3725 840 7347 4084 8665 9438 9786 4026 726 896 3979 3608 7636 9137 1367 6897 7524 3758 4964 308 1415 8606 9412 7220 8019 9896 3410 1130 8183 5079 5311 2720 815 3697 1782 5152 2376 8992 8207 5567 6093 6350 6286 4873 9923 9451 9895 7286 9314 743 3608 7588 8946 6914 8589 8015 4648 116 8944 1687 798 3276 2855 5567 9792 843 3532 4919 9220 9964 714 3382 7436 7087 4850 3686 2924 8133 5574 1829 7497 2835 4366 9916 4374 8560 8452 8167 6382 2146 2723 4257 9888 2015 3991 9628 7618 2333 6738 556 6260 5204 8836 1570 5303 6940 8757 3653 2892 8554 1500 6873 9542 8413 8100 266 3516 8157 8386 8475 4566 57 912 859 3459 3640 6445 7427 5423 9242 4281 91 5656 7755 8013 1779 4404 6626 1814 865 2758 3780 6281 3309 9765 2416 2127 2186 434 7806 1143 4334 5752 8008 9695 4535 5605 5975 4907 9822 7411 6535 7698 7954 5745 3108 7281 5174 9365 1548 5594 6914 5255 9752 7613 3190 2004 3518 7526 4735 9123 208 8422 6644 6415 5318 5952 1358 6880 6399 1177 585 1433 4695 6568 8771 1670 9344 7266 2417 4846 9376 321 235 8411 1342 2996 1039 5463 3023 4165 4662 5484 6192 8485 325 5282 3225 2789 4011 466 3885 4374 6057 9626 8841 4902 5335 1863 8959 273 4681 6603 1705 2605 9458 9735 8054 2153 766 3267 3222 489 9231 7230 4354 5846 2955 9781 988 6826 6058 8594 1699 876 1753 1624 1581 8050 4653 2366 3292 944 1176 8981 4301 2334 8249 3767 9325 3747 3025 684 5259 1410 7002 7110 9574 810 4380 160 3006 8687 738 8052 4909 2918 9966 2460 4612 2259 5601 3240 5057 9878 2074 77 2988 4524 8339 5109 3078 447 2944 7791 9022 1845 4658 6618 2362 4845 7146 306 4788 1719 6472 4957 2091 9277 5680 5926 4814 4552 7462 4550 6032 8260 9790 5716 9321 6866 5342 6053 7225 3517 5237 2191 8494 499 5120 6918 9413 9378 6565 4351 5885 1874 6184 1123 1212 2948 8967 8013 1796 3934 9886 1794 6295 4158 1112 1263 3553 395 7979 1495 5038 4676 345 7868 8958 8060 1953 3829 7482 1642 6570 6983 3293 6270 4947 7613 3137 2691 3622 3627 8031 4482 5938 6772 9462 1026 6995 9101 8964 1792 1129 5416 2608 4428 7156 5110 9705 9773 1513 6971 3768 797 438 3932 9336 8644 4780 7695 9803 8767 3773 1161 6147 2933 8353 1148 3207 3521 1410 4598 6057 9292 7387 4774 161 7852 8107 3693 2814 6377 1637 6332 6581 7775 4753 5013 3532 507 2202 5543 7495 4546 8887 9582 7499 3550 4601 58 6176 8420 9312 2480 8388 7417 5363 9093 1190 4647 7492 8126 5394 4661 479 4087 9359 9873 8617 5884 5824 2344 8773 7621 79 6052 3961 723 8965 8655 7596 416 8057 3595 2167 5208 1874 8781 4322 8162 4018 2984 2314 9896 4979 1691 3970 3738 8612 1158 6977 9765 2231 6393 6255 1824 7755 872 7706 7853 3705 3170 6688 7053 260 6796 8505 697 6785 9028 3646 6660 7302 3670 9047 9246 5171 893 4814 9319 3633 2239 798 4855 1902 866 2853 4395 1300 2989 7816 5698 6518 4809 8273 5517 583 2458 4166 5816 1082 9747 6667 2049 4972 1738 7567 1797 8831 4468 6734 1982 4696 9638 4983 8291 701 1193 2251 322 5193 1812 1512 9362 2673 5629 8975 4172 8030 985 440 9714 4277 7929 160 9074 9077 4915 9126 5965 8618 3050 7649 6448 7809 2463 6094 4218 3181 6712 7578 7758 8619 6938 7559 1254 3380 5268 5370 1415 8486 4802 7533 7959 1337 3760 837 8455 1571 568 1473 2593 3336 6026 3671 6181 3511 324 5878 4284 9205 5379 1266 8127 887 4975 5440 5007 751 1952 8814 7241 3437 467 8198 2772 4438 9837 9025 5758 506 9029 1219 6295 3475 2663 1617 4365 8164 4894 6732 4218 98 5649 1634 5280 375 5594 7540 4820 3535 6105 8570 1596 2538 5126 1104 6091 7810 2298 518 8202 7874 9057 7214 925 6069 2431 8756 9752 4555 7061 9278 8847 1918 792 5039 1939 2003 3006 5829 5077 9753 8072 7805 5403 4570 7226 8316 7437 2050 2942 2266 4986 6843 4849 2584 6848 5705 6362 5708 7189 5074 5842 7609 7157 2143 6162 4372 2964 6874 8929 4819 7237 6471 6314 2698 8721 1742 5173 4805 8919 946 7887 836 9339 2431 8261 7781 2725 3481 3557 9859 7856 255 6387 9832 1499 1327 1370 9872 8650 7560 9425 9659 3237 5753 1114 1978 60 3263 9632 2300 3949 5235 2430 3307 805 4803 6822 2753 3960 1318 5641 7421 7224 1966 8060 5322 3920 2460 9518 4104 9713 5708 6978 3989 9221 6805 3052 9265 1551 4415 714 4820 1549 9708 1764 2264 4618 504 1035 2841 6864 2243 6526 3904 7132 5477 5731 3890 177 6038 6247 6479 7119 6764 60 8284 311 6517 5435 8088 593 8265 8623 2917 5605 2481 9437 8315 8912 2257 5443 7576 4412 4867 8965 6404 8859 5426 7598 6331 1965 1890 505 1409 193 9826 2375 2530 2389 7325 5960 7077 5979 4108 5512 3499 4229 5303 5588 8988 9677 3367 1281 4120 9892 5961 9787 6904 5284 4570 3870 8364 1997 3673 2667 5937 2148 3164 5752 1161 4676 1681 6237 2454 9677 5286 7061 7977 7813 1296 2174 4856 667 6028 7574 8487 4596 3310 4033 5472 2469 6071 6209 7847 4001 4775 9011 2291 3400 8568 1734 8540 9124 4872 7079 6577 5849 7547 6827 5092 8463 8662 5636 3751 3275 4069 8067 2903 8020 5037 495 5515 232 4999 3038 8335 1227 3365 5830 7295 4750 2316 4622 9256 8438 5503 5087 9640 9589 2599 3727 1607 4196 9887 8641 4009 5356 3460 2501 8674 552 8198 1321 3448 5070 3718 2799 6738 5282 2029 5728 555 639 8996 6496 4249 6188 7904 5793 1768 1264 9793 7968 1777 6051 9725 1786 4343 3586 4116 8860 3895 9219 3846 4273 7290 2538 9854 1052 5635 1477 4128 8753 2107 5316 8873 3511 5298 4000 7842 187 9479 5376 366 8502 1995 77 7793 9410 7633 4981 5084 4496 319 5016 3360 6203 2715 4477 4183 4926 1929 5373 2672 6384 5658 7112 3627 5253 7480 8877 6948 7039 7426 9982 3789 5149 259 6569 3708 2005 9123 5621 6052 3646 4479 160 9165 8689 5284 3481 6695 4076 8035 4553 7666 9051 7907 7668 8202 3367 4042 7001 2155 2477 5910 5240 3659 8552 75 3019 4108 8284 6548 3180 4400 4412 169 8107 7285 8613 1814 4109 7723 1659 5130 8773 6134 5125 764 2024 7760 2150 8603 9299 1525 9694 2184 1270 9941 8561 3726 5484 277 5417 3249 9445 5346 5387 999 8337 7973 3956 3678 8069 6756 4836 4700 6520 9911 3330 9937 4568 7151 9359 7639 8327 8897 1393 839 511 1498 7918 5211 5633 3328 4197 6652 6904 8066 3769 8948 3104 1485 2858 7983 2615 6799 7436 8631 5404 3513 4675 5425 9367 6275 6615 391 3821 7518 7876 2437 1411 2378 3048 8318 3371 5263 3414 8103 8869 8264 4281 3391 5583 2962 2446 43 3070 5982 5775 4028 3663 2759 4092 4740 2216 7388 3051 6028 725 7392 7397 3715 6834 6930 5531 3790 2497 5091 8327 9458 1603 1841 4641 1762 6307 9172 6733 2978 4670 5990 5857 7102 9849 2168 6699 3486 270 7733 5350 9498 7745 7576 400 2142 428 6730 9459 4980 193 8750 1370 6139 2749 9530 6653 3367 5650 3793 9049 303 6042 7389 43 5109 8308 998 1660 6175 6772 6505 6878 3016 5199 1061 4960 2973 8697 4255 3224 630 3575 5064 3900 854 4750 9961 9804 2123 997 7616 321 192 4827 5506 9173 2615 9157 5042 7857 5002 1703 9013 6656 2739 4337 8698 2324 2476 1892 2453 8641 3411 3005 2265 2363 4863 5902 8642 5068 8652 614 6268 932 4937 3928 613 3340 8405 7369 1099 6082 8862 8635 8777 8300 156 5807 104",
        "5065 3468 9318 2904 8437 524 1483 3646 4419 3468 6593 6935 9455 9176 4611 9713 3053 528 9774 1789 1156 1309 5898 7902 3654 2561 5215 8968 4516 7876 4111 319 2901 5999 3052 4647 4142 6808 6051 5366 190 3253 4412 3602 6284 9164 2696 3863 7192 2250 5844 2367 8815 4895 6766 2745 4204 7274 3501 1760 3540 9125 8120 3764 9869 6329 2133 3104 7396 6642 2785 893 5339 2001 5718 561 444 7041 2844 9562 2191 7516 7393 1639 5548 4609 993 6040 2415 6916 4835 7557 8849 2226 7436 6164 6330 1959 5348 3001 8224 740 284 4752 9570 5672 8032 2951 4740 181 8689 7716 7643 1311 1256 9946 5007 3108 3111 3284 5542 6931 2277 5731 529 3839 5777 7790 7705 5970 6989 574 2437 6348 8999 9582 6800 1228 763 7645 283 6181 8259 7092 267 7853 208 5941 3375 6417 8999 114 2096 9322 3742 7786 5129 6522 9137 1552 4083 3575 6452 6726 7839 8117 1764 9385 7396 8580 712 3229 3504 4492 542 8344 6964 9373 4844 3621 8657 3525 3497 4781 3649 8175 10 5300 3856 1091 3259 9666 4553 5657 8116 1440 7858 3281 5102 6963 444 1585 4920 4157 7992 9562 9770 1440 2239 2209 2325 9263 332 5548 7975 184 7881 9910 1683 7543 6112 8112 5893 1138 5808 4749 1498 2099 667 9293 1567 5860 1332 7271 2609 4049 480 3610 8754 2040 5047 4511 3313 2793 102 2015 693 4380 6384 4753 3124 8741 7696 4708 6559 6626 1609 1358 6927 4890 4987 35 4221 2285 8183 5426 5214 1858 9970 3485 8403 2941 2108 1682 2934 2445 9936 6434 1161 8250 1480 2331 275 2220 849 9865 1091 9011 9098 3928 7789 6867 938 2017 7308 4715 5709 7549 1504 2090 2750 7138 2012 1347 2369 131 6174 1183 7068 7983 9334 5391 3002 8921 3529 24 1344 2414 8455 4837 1049 495 2292 4426 4179 7639 958 1028 7148 3980 4374 5595 2003 1059 3705 8309 5081 1761 9291 6246 3606 8 6075 4997 6059 5556 178 1677 1349 5448 1748 8801 8731 2587 2467 6873 334 5689 6023 2693 7187 3683 3431 8638 9881 7256 9413 2346 4973 6859 2357 2827 5026 1697 6131 6897 8790 3911 9799 5651 1474 7429 6595 2116 1744 744 3925 1098 9893 8840 5395 2135 1416 7204 2916 6464 23 6980 2383 1915 5896 5055 3542 1628 349 387 2004 4035 4040 7953 54 6416 9637 2431 6386 2415 1219 1334 5368 4483 3589 7749 8137 6989 9114 8936 6904 1720 8900 9537 8288 1405 2162 5325 7251 957 3518 789 5373 4691 8782 6153 9031 7105 3171 1160 3375 758 9230 9132 2697 2687 5840 1056 3767 92 2859 1576 5696 3438 5520 9128 6290 26 4332 8968 626 9697 769 8048 5598 3127 286 4877 5300 3274 1811 6265 9933 6249 8747 5895 102 6324 115 514 9073 5658 8434 6967 57 8547 286 9729 6008 4045 9618 5408 1418 1939 644 3771 5917 7226 1806 1979 7580 9800 8354 9224 1276 1618 5722 2165 10 147 5305 4881 3294 6158 9245 5117 3625 6653 8401 4110 8109 8478 8681 272 8346 6457 1576 3963 8018 7062 8157 2015 1090 1878 2637 7990 4345 838 5628 7394 9894 7835 2796 3923 1941 9114 351 4444 4634 1638 6627 6622 5104 419 9666 7630 342 7368 7389 370 3896 4812 1702 2130 1901 7317 4063 7873 9098 382 2329 281 4984 5944 2997 7861 266 4860 3525 2583 7010 4155 1107 7100 6057 4728 818 8199 5900 3011 5896 9358 8001 5002 8960 6873 4981 4544 6306 2635 6829 4911 9359 1119 6874 6836 6575 3289 4870 2276 9315 2045 6860 7529 3298 7648 635 4731 1029 5419 6001 9690 9669 486 2192 1594 6804 7308 3935 9441 4204 5963 1593 4524 9135 6768 5921 3530 7338 6560 7502 1234 3776 7817 5837 311 7996 2077 597 4390 8451 8979 4243 975 1822 9253 58 3803 3962 5244 5176 6641 5335 1878 4362 4284 6736 7686 382 3208 6012 1446 3004 2001 442 6719 5676 4174 9189 1229 7179 2818 7811 8832 9817 397 7618 9692 4229 9824 4729 147 8305 1279 709 130 1080 770 2038 7584 2783 6727 357 188 6724 4897 5582 4703 815 7973 8752 6075 3397 8423 5074 5272 5224 8729 9992 7553 7813 2687 6942 4995 6358 6495 6582 1820 3361 2490 5527 9248 3679 9262 5367 433 8720 7542 9615 6256 5567 2748 2042 9156 9873 8184 3332 5963 781 8718 9530 2494 7027 1242 5756 6068 1991 3847 7067 8290 8573 7595 3643 3193 6682 6530 9551 6853 8477 2005 4371 5265 9811 423 3298 8016 6693 3869 2856 6171 1782 356 5093 4772 2018 4031 2938 7311 106 1675 9719 7059 9637 5922 5070 717 3543 5076 1266 7352 7141 8606 8476 1443 1218 1418 8597 4410 130 3757 5511 595 7729 9565 6304 6459 1090 4464 8827 4031 4292 7579 7888 4803 3132 6213 7472 5139 6985 4552 5345 1061 9130 4399 4580 6995 755 7047 6736 2564 3004 8185 958 5384 7818 8869 5132 176 9475 4061 587 2284 231 7783 5669 1218 9573 6406 1300 6942 4468 6559 659 6718 7078 4841 3294 9482 8540 3542 2538 8505 4042 1735 3626 5723 9664 6889 8984 781 4441 1855 9160 1802 2480 2197 5425 9871 2753 7422 5515 8617 118 6867 3306 6793 8769 7820 2811 6449 6965 273 5174 4991 6523 3739 8211 9310 5335 5257 630 1314 8075 9695 1148 5633 3513 406 3805 209 8186 442 7417 4681 3163 2114 9868 2280 9585 6523 3310 4786 1045 6618 175 759 7792 8143 8066 3118 7874 6119 3883 3509 4417 5102 4089 5749 2526 2610 3122 7757 764 5468 5393 1010 7295 9579 4012 1601 6680 3189 8559 4642 50 9515 7984 6903 8498 5299 1442 248 3353 3223 4397 5956 3603 473 9954 9548 2725 5983 7147 6034 8902 1085 6536 6750 8233 1947 560 3154 9226 3007 5883 8353 50 6698 7789 7380 2675 4089 2187 8636 7716 6923 560 6278 4967 3660 72 61 8038 8951 8489 4168 3660 5673 9457 9458 5792 4238 1762 7152 2381 2754 8785 3726 1772 882 9828 9061 6543 8405 2024 8032 5837 5401 793 9301 3324 9060 8217 2114 6833 4864 8514 9190 2259 8321 2226 5130 6866 3973 4772 4959 9639 447 5236 2105 7853 2922 55 7701 5446 9540 8476 1096 9534 7067 5369 4114 5839 6189 1646 2042 4737 4274 2860 7263 2309 889 3742 1599 3377 660 5944 9255 4684 1387 3578 3604 3323 3697 1540 2201 705 529 6454 7314 8002 9381 3226 1218 6798 9474 8926 1042 1060 9146 5373 8008 7387 9319 5140 9827 795 3434 7368 1144 2652 1929 1044 3850 3153 1556 2748 317 2688 1145 7546 7688 6832 8837 648 9966 7816 8285 9843 4969 2748 7875 5876 2855 6836 1944 9227 2073 6504 690 6224 9024 8322 8530 8704 516 1643 2224 2614 7554 2618 5304 9036 2961 6029 2543 5068 6877 3882 6641 8325 1807 6900 8653 4401 7753 5882 7268 131 7841 3061 9079 8406 8998 7037 1311 4887 4525 148 3577 2891 7769 7554 3351 9584 8614 5459 8582 3095 222 6338 3501 4953 6234 141 1932 5850 8938 4920 5319 4185 7176 4056 4144 8989 6771 7637 8799 7027 4864 6581 158 1506 142 1001 5234 549 3272 8776 7443 6174 5267 1567 867 4033 6951 2541 7681 8586 7825 1028 6395 799 8922 7497 4206 8007 5485 2852 9187 8562 9148 7208 6945 288 9438 3572 723 7197 7898 2953 8512 4342 4795 1502 8752 9841 7730 3759 9482 1502 2620 6706 6029 8770 4298 2529 3475 3518 605 1738 9170 2991 5245 7260 9305 663 8776 958 250 9088 7961 957 4054 876 5136 4130 834 8582 9875 7768 6236 5108 2053 817 3678 6069 2256 3399 1988 8977 5272 2542 2494 9981 1386 3285 9703 7867 2441 2184 7294 5662 2934 6598 9859 5127 6664 621 6344 788 4878 4257 3873 637 228 2130 6038 8177 4177 5315 8171 9910 6794 8538 5457 617 896 4229 3113 1991 56 9178 6267 4382 8206 3876 6639 2616 6729 6678 3898 2317 6772 1107 1558 2306 7573 3009 8095 6217 7573 40 6849 7995 2738 478 2217 8127 5834 8967 3024 7726 915 1277 4107 7536 6337 1605 5069 2244 4265 4534 5167 9214 8043 7140 8811 6556 4945 7413 4511 6138 5955 6335 2156 100 6038 1591 8836 6081 2321 2762 3536 5714 1280 3526 8273 8639 5341 2401 9913 8008 3433 3328 6548 2193 5899 1746 3272 4917 8752 1480 7622 578 4849 7878 5756 3395 164 8987 7623 7348 6539 9289 8044 7190 2438 6226 4932 6794 1870 1051 6411 9468 3976 4085 1713 4354 7859 3337 2454 8476 4150 2968 6324 3184 6599 3272 5055 4787 1096 6338 8338 201 8630 80 4524 8805 5600 6377 2765 5050 5628 8684 6558 9266 638 1414 424 8734 2681 7423 5762 9268 6550 2621 6245 742 6199 8304 7894 9978 9693 8979 2844 3009 4126 2741 8280 7525 2178 967 8550 4726 5507 6771 8948 426 7388 3477 4629 5904 9841 9232 777 9792 8513 1596 1286 7462 4769 2050 7574 5683 776 8326 501 8910 6978 1957 3771 3084 6034 435 1315 7139 6178 9453 3465 1540 8576 2846 3387 3106 7716 9167 184 3260 1175 755 9401 8151 3587 949 2561 687 5920 128 5600 9179 8383 8141 6217 3629 1031 5686 9350 298 2169 1634 8960 5282 3746 170 784 1373 9463 596 3125 8680 6330 8039 9219 4146 1567 7518 1323 1729 2321 821 5629 7463 9584 4184 2205 1736 9092 5006 9723 6158 2554 6834 9906 3221 2793 673 8785 1374 1777 204 8901 5233 9386 7899 3413 4289 4997 8953 7115 4703 9173 3831 989 4239 167 1684 6688 8449 7013 5518 4545 1912 8127 1967 630 5863 7345 790 8536 4599 7628 9462 8652 8329 5916 1416 3233 6101 2793 2629 2533 4783 1739 1317 8424 5883 2938 1185 4273 5228 1398 2223 2983 3582 6951 4279 9756 5576 9180 2307 2075 245 2524 9196 1214 8571 7032 273 5297 5402 434 5589 3714 5879 9911 842 1536 1727 3651 2507 7321 2022 6228 6833 4988 2959 4701 523 1994 3795 4428 9710 2797 7413 2623 5407 8060 6349 312 2451 8047 3466 1939 2042 2457 2810 7648 307 8312 8352 5132 2755 4593 8733 9514 5924 9485 8210 9583 8566 5786 320 3648 3869 3590 4261 6115 4230 3283 9924 3762 397 8603 6064 1341 6821 3962 2718 1205 861 8022 8484 6328 3816 546 5221 1885 6555 4865 5614 3061 9341 5870 9486 1775 1134 9968 1821 4531 523 9787 3636 8125 638 3690 1897 6019 6194 6287 6044 3541 6013 4789 5885 2580 8184 5166 5279 7696 7962 4438 2553 7365 2224 2743 9084 2958 370 3865 4368 2191 4106 6627 6211 2295 151 6046 1929 1931 819 2556 8441 4618 3882 2614 1517 1252 9024 6602 3604 3816 4543 3742 3977 5998 7741 4035 2357 5980 8612 3686 3338 7633 2326 1835 7651 997 585 3539 8400 2559 1759 5681 5948 6695 1368 7162 9277 46 3278 9779 219 2619 7608 14 3543 6512 3282 6212 7723 1993 3709 8027 4061 8545 907 5038 6847 1900 3148 3028 785 4829 1750 6910 15 963 9977 1314 6125 3937 3880 9139 6611 1547 1686 9784 1863 6114 4756 8972 2396 6039 3969 4423 2740 5709 7461 2090 4882 3250 7074 7940 3729 8910 4813 6328 7251 5637 9145 5188 6114 2280 1028 3375 5097 7178 9805 8582 4081 1864 82 1154 683 6076 2633 1321 9212 6293 3850 2746 9273 1353 1754 7864 6852 4654 6424 1950 934 9912 9704 2544 4224 4650 6531 3981 9013 627 5015 1738 5101 6376 162 9102 530 7365 2264 2954 288 9257 4714 6890 6841 5871 7709 9345 4223 8843 1371 7156 9997 3122 583 8856 8854 6918 5142 5790 729 6056 5037 5209 91 7475 2217 5994 4016 3236 5276 9682 3596 5118 4753 9101 2930 7911 4628 7952 913 2407 7290 1513 9722 8739 6685 7615 1237 848 4601 1674 8916 9395 4065 3750 5714 502 915 8245 4404 8398 2272 947 7966 3115 3691 8218 9952 5372 1479 7087 971 6780 5194 2358 6867 7333 3661 6141 5319 7398 6194 4181 8681 488 9413 5624 2372 3592 4776 4685 5754 7279 9918 6929 5718 7210 7116 5897 4881 5018 2746 4033 9096 2733 5845 9110 649 6793 9885 9924 258 285 8245 9587 6736 7160 6402 2270 1292 3946 7252 5673 4988 3959 4830 6727 1561 3304 4334 3551 6383 6563 5055 5650 575 8644 4775 5085 4875 569 8421 3716 2349 2866 8 8493 8430 2526 6703 1131 1 8393 5634 2717 6064 8746 8344 5166 2581 3686 6414 7341 7483 5421 2389 2491 4628 7779 5406 1148 7592 177 7702 8666 137 3763 2785 7425 1193 6725 9809 8017 8025 2312 7804 3852 2487 6616 206 9460 3830 824 2373 721 7027 6912 2239 8124 2508 4444 2531 1284 3624 3250 9927 7428 641 5698 3706 2133 1590 1278 9950 5488 2417 2311 1268 8102 9000 9338 2294 9033 1510 4472 1883 4642 815 3105 8269 733 1924 7405 7649 8356 8992 3659 6798 5389 2302 1678 4019 5887 633 6202 4878 3034 535 6871 4527 7225 3347 9457 9569 8230 4481 3349 6461 1715 821 342 459 2151 3863 8844 2601 9219 1208 4494 7612 4270 180 1997 338 582 9686 7250 1786 2188 6507 1410 2459 6543 8357 7412 960 2314 3614 3194 6536 8426 473 7723 1428 5832 7299 2055 1772 7837 4738 1744 9297 3168 5854 3832 4808 9842 1355 5686 1564 9905 1813 4465 4153 6699 9653 2621 1706 2324 2395 4094 9456 7471 1467 7125 7594 226 1277 8292 1821 1282 4618 1406 6673 7641 8313 3787 867 3239 9918 8430 5028 9115 3200 8808 7395 3560 1620 2341 7406 773 3732 3038 6982 554 362 3914 5972 8965 7072 8833 9522 5980 9964 3872 1629 7457 9249 5598 2936 8654 4423 8029 1808 5692 6363 7898 2724 340 5937 1620 5691 4585 3829 2018 1339 4793 859 7994 9110 5718 90 432 229 8804 979 5883 7337 4562 2426 6082 4773 4685 1367 1488 6246 6670 5294 8636 7254 3940 8834 9537 7635 5432 1467 1564 5786 4196 9698 4108 8398 1147 6071 6637 129 8777 3718 7276 1937 2909 6772 269 8691 7636 739 5354 5368 7885 622 7973 4073 4164 5176 8372 9859 1992 9961 8547 6304 8083 8371 4531 7735 6967 6203 8487 4649 2312 1251 2755 5704 6760 4718 3721 9625 3253 747 7997 3642 4160 8945 143 4941 7989 4638 9876 6417 6310 1403 5397 4820 1068 8370 648 7570 9757 4957 6818 8031 4805 7786 5162 4308 1181 1265 4767 4961 3332 2575 7193 1687 8950 9663 7276 302 2666 5036 6437 6816 6641 8535 1619 5967 9144 4045 3287 5697 3044 2126 7995 9069 6936 6212 9940 5255 7709 9896 4700 9887 5213 1985 9120 5374 3217 150 9400 8410 828 1945 1942 5721 7850 4534 4321 4469 9903 9064 7079 1232 6161 1276 8506 1095 4849 6259 2388 2676 1900 9292 5311 2991 152 1043 1042 7518 7340 2780 9211 1556 968 4331 4561 6931 7338 2983 8759 6290 7320 4994 3105 4289 889 1870 2896 8593 4640 2978 3613 2026 5175 4746 6524 9113 4693 4912 5783 94 4758 5172 2798 2968 7127 3935 5405 9977 7940 4688 8227 8263 8795 4403 9329 6246 8989 5933 4106 3506 8078 1639 6177 7200 2340 6141 886 8350 9534 5118 8949 5446 1921 2183 4719 2782 8384 7623 8872 9532 1484 2004 2136 1456 2840 9519 4004 6572 3370 7072 2448 8044 7612 6197 5294 4571 6038 4977 8064 6905 7726 7465 3842 3727 2700 1663 9762 5108 5655 9955 1669 5587 9379 9857 1902 6382 8802 9678 8241 882 4120 7857 4130 4713 9398 1850 5062 6436 516 536 9369 6040 7463 2443 9526 9940 6746 3426 989 6071 9215 6952 4489 34 8284 3733 1925 807 4112 9306 4694 2650 6208 5197 6706 8760 5980 6690 20 5980 6691 2218 4116 1233 553 9454 8223 3981 605 4058 6759 5348 4823 4565 9695 7947 4968 7928 7414 5610 1771 9954 7003 633 8812 6653 3804 1658 3713 4518 7662 5205 4639 4649 3475 4897 6786 1451 511 6090 7256 2124 7956 9431 2469 2474 4101 1684 2745 5359 9326 4692 7821 3800 9060 5822 8342 1722 5398 5365 9936 8065 4909 42 1603 3929 8713 7132 1962 5640 1475 9005 7036 2535 4696 4073 3745 9294 8184 6282 2917 9229 2854 5033 2140 1944 4594 3629 4809 654 9206 768 669 604 3883 8087 5907 7874 7274 2970 4417 9852 572 8579 4277 6268 5340 1242 2159 1583 2451 1324 2630 2026 9074 6266 8423 2324 9733 6254 4419 8528 5410 3154 23 7207 2604 8313 2423 3162 6019 8796 6262 4108 4435 7635 1563 8990 1700 6409 233 964 2857 6620 5339 7124 1318 657 3998 6610 6101 1465 4779 4202 9826 8195 5656 5128 9378 1200 9033 2114 4983 2966 1018 6198 822 6865 2493 2203 6327 1944 7363 5453 1581 5705 2591 585 7471 3627 5459 3461 245 7984 6318 7056 6907 245 6231 1669 9930 1825 1918 8323 4125 1772 2130 2177 2234 5398 2467 3158 2833 2589 6177 5848 8680 974 5596 6971 4333 3117 1784 1729 9856 652 768 337 320 8119 2027 8893 3901 7573 5681 7748 274 5510 4438 5471 7464 1768 4161 1124 9389 2686 6351 9485 2169 4879 9192 2178 6813 4648 2878 5609 7423 8410 8933 2398 9437 5435 9785 3496 6987 2028 8343 4953 9919 3243 7944 8879 8991 2877 3564 3739 9693 2382 6868 4515 9335 9588 9215 6337 2443 7725 2564 803 3827 6523 5731 7762 3410 2685 9061 914 5569 3094 4664 1938 5234 1415 5831 4187 9900 5511 7878 5620 6777 7800 2148 8979 9160 5847 4927",
    ]

    for input_str in test_inputs:
        run_test(input_str)

if __name__ == "__main__":
    main()