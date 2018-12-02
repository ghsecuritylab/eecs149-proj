#include <nrf.h>

#define PIN_MCK    (13)
#define PIN_SCK    (14) // same as BCK
#define PIN_LRCK   (15)
#define PIN_SDOUT  (16) // same as DIN

int main(void)
{
  // Sine table (stereo, so every value is duplicated)
  //int16_t wave_table[] = { 0, 0, 23170, 23170, 32767, 32767, 23170, 23170, 0, 0, -23170, -23170, -32768, -32768, -23170, -23170};
  // int16_t wave_table[] = {72,470,866,1240,1606,1968,2292,2584,2854,3086,3288,3464,3600,3704,3772,3810,3812,3780,3722,3656,3590,3528,3484,3460,3464,3490,3524,3558,3598,3638,3684,3736,3808,3924,4098,4316,4578,4888,5222,5568,5906,6236,6536,6814,7080,7314,7530,7742,7934,8114,8280,8432,8568,8690,8806,8910,9008,9112,9212,9316,9426,9538,9654,9768,9880,9984,10074,10138,10174,10182,10168,10138,10094,10048,10022,10014,10024,10048,10082,10126,10174,10216,10254,10294,10344,10404,10480,10566,10666,10778,10910,11050,11200,11370,11546,11738,11948,12154,12360,12574,12776,12976,13174,13374,13568,13762,13960,14152,14338,14526,14700,14864,15022,15164,15292,15406,15512,15614,15724,15854,15996,16156,16349,16551,16761,16971,17167,17355,17535,17713,17877,18043,18221,18399,18583,18777,18971,19169,19371,19563,19755,19947,20151,20355,20565,20797,21031,21277,21541,21801,22067,22349,22629,22915,23207,23525,23841,24171,24525,24881,25249,25641,26023,26411,26803,27213,27611,28011,28423,28813,29195,29577,29927,30251,30565,30853,31131,31395,31655,31889,32107,32311,32475,32601,32693,32748,32767,32767,32752,32715,32665,32603,32535,32459,32371,32277,32173,32053,31929,31795,31647,31501,31361,31231,31109,31011,30935,30879,30849,30833,30829,30835,30849,30869,30891,30915,30941,30971,30997,31017,31027,31023,31009,30983,30943,30895,30839,30787,30735,30683,30631,30579,30521,30451,30369,30269,30147,30007,29843,29649,29439,29207,28953,28667,28375,28063,27721,27377,27019,26635,26259,25881,25487,25109,24731,24357,23969,23597,23225,22833,22449,22055,21633,21211,20771,20295,19821,19343,18859,18355,17869,17385,16883,16393,15890,15354,14820,14270,13680,13092,12486,11864,11202,10546,9876,9166,8474,7780,7064,6380,5706,5044,4376,3748,3142,2536,1974,1440,916,442,-4,-434,-820,-1178,-1506,-1816,-2088,-2338,-2576,-2790,-2988,-3182,-3362,-3534,-3708,-3874,-4040,-4200,-4360,-4508,-4646,-4776,-4882,-4976,-5064,-5144,-5220,-5302,-5394,-5502,-5628,-5782,-5956,-6154,-6384,-6628,-6888,-7174,-7454,-7734,-8020,-8286,-8532,-8760,-8978,-9174,-9356,-9536,-9706,-9878,-10060,-10232,-10396,-10560,-10712,-10852,-10982,-11110,-11230,-11356,-11492,-11624,-11752,-11882,-11998,-12104,-12200,-12278,-12348,-12410,-12468,-12520,-12566,-12612,-12656,-12714,-12796,-12896,-13020,-13178,-13360,-13556,-13754,-13946,-14120,-14272,-14402,-14498,-14574,-14636,-14686,-14730,-14788,-14860,-14952,-15064,-15204,-15360,-15528,-15706,-15870,-16028,-16186,-16334,-16479,-16621,-16759,-16893,-17025,-17159,-17281,-17399,-17513,-17615,-17709,-17799,-17877,-17949,-18019,-18099,-18189,-18295,-18419,-18551,-18697,-18863,-19031,-19205,-19393,-19585,-19789,-20003,-20239,-20479,-20733,-21007,-21275,-21545,-21825,-22087,-22337,-22581,-22807,-23037,-23273,-23531,-23791,-24069,-24373,-24681,-24991,-25315,-25625,-25935,-26251,-26551,-26841,-27115,-27381,-27623,-27863,-28111,-28351,-28585,-28823,-29045,-29245,-29411,-29527,-29607,-29665,-29719,-29763,-29811,-29875,-29955,-30045,-30137,-30219,-30295,-30373,-30449,-30523,-30603,-30693,-30789,-30891,-30997,-31099,-31197,-31293,-31375,-31447,-31511,-31563,-31605,-31635,-31653,-31655,-31643,-31613,-31565,-31497,-31407,-31299,-31171,-31019,-30859,-30689,-30511,-30321,-30141,-29967,-29791,-29623,-29451,-29273,-29103,-28935,-28763,-28605,-28459,-28333,-28217,-28119,-28031,-27951,-27877,-27803,-27725,-27647,-27567,-27485,-27401,-27317,-27233,-27147,-27067,-26999,-26943,-26905,-26891,-26907,-26949,-27011,-27085,-27171,-27253,-27323,-27373,-27393,-27377,-27319,-27217,-27067,-26853,-26591,-26273,-25907,-25479,-25021,-24531,-23993,-23453,-22897,-22303,-21721,-21125,-20493,-19865,-19217,-18549,-17833,-17115,-16375,-15594,-14832,-14066,-13272,-12504,-11744,-10960,-10214,-9476,-8750,-8020,-7344,-6696,-6056,-5466,-4908,-4354,-3834,-3322,-2800,-2300,-1806,-1314,-814,-354};
  //int16_t wave_table[] = {16,226,442,611,772,951,1042,1124,1157,1378,1530,1698,1816,1938,2068,2187,2314,2476,2726,2985,3173,3314,3383,3410,3421,3519,3631,3714,3662,3537,3288,2983,2658,2308,2005,1729,1454,1115,729,349,-3,-322,-501,-561,-561,-608,-718,-831,-962,-1026,-970,-857,-651,-384,-79,200,446,657,865,1074,1292,1559,1846,2106,2345,2552,2727,2867,2997,3115,3247,3360,3495,3654,3790,3909,4038,4221,4437,4612,4732,4751,4702,4627,4598,4601,4581,4484,4329,4108,3802,3469,3128,2809,2546,2311,2110,1948,1866,1826,1825,1806,1751,1639,1504,1396,1359,1426,1531,1673,1744,1689,1524,1309,1135,952,779,618,458,312,136,-73,-326,-539,-726,-860,-993,-1104,-1222,-1356,-1487,-1627,-1772,-1948,-2161,-2466,-2850,-3245,-3616,-3937,-4227,-4481,-4728,-4974,-5197,-5430,-5653,-5859,-5956,-5950,-5872,-5742,-5591,-5481,-5413,-5395,-5369,-5323,-5252,-5148,-5033,-4955,-4852,-4725,-4564,-4357,-4097,-3813,-3537,-3271,-2983,-2697,-2421,-2134,-1828,-1488,-1194,-954,-760,-633,-615,-634,-642,-675,-698,-682,-648,-720,-701,-687,-633,-616,-607,-577,-547,-418,-310,-202,-134,-13,172,377,559,706,866,1037,1114,1190,1231,1476,1648,1821,1928,2032,2150,2281,2443,2646,2933,3218,3431,3612,3726,3798,3827,3909,3982,4028,3971,3862,3636,3346,3038,2719,2454,2216,1976,1669,1308,938,580,248,58,-20,-52,-146,-312,-475,-651,-760,-754,-706,-569,-367,-124,92,271,417,572,723,873,1060,1270,1473,1661,1811,1915,1975,2037,2092,2162,2206,2261,2334,2380,2408,2449,2543,2676,2775,2838,2821,2753,2673,2651,2668,2671,2612,2512,2374,2169,1944,1725,1538,1421,1341,1295,1294,1383,1515,1674,1797,1873,1892,1883,1887,1948,2107,2312,2561,2743,2803,2755,2667,2627,2583,2556,2548,2554,2581,2584,2558,2488,2453,2428,2442,2441,2449,2435,2382,2313,2221,2110,1959,1771,1492,1140,775,427,131,-125,-339,-540,-746,-935,-1138,-1340,-1538,-1639,-1647,-1586,-1475,-1347,-1264,-1238,-1268,-1296,-1316,-1321,-1307,-1286,-1301,-1300,-1284,-1238,-1141,-977,-782,-590,-406,-197,11,210,422,654,918,1133,1293,1411,1460,1393,1282,1173,1039,908,808,723,534,438,338,276,178,74,-5,-83,-55,-44,-32,-63,-39,51,163,243,271,299,329,259,182,64,145,155,173,132,96,76,64,85,155,312,472,564,631,644,616,545,530,508,454,287,61,-284,-687,-1116,-1566,-1961,-2325,-2683,-3100,-3570,-4045,-4494,-4901,-5147,-5257,-5302,-5393,-5546,-5689,-5840,-5916,-5872,-5789,-5622,-5395,-5129,-4881,-4672,-4501,-4321,-4143,-3960,-3737,-3503,-3282,-3075,-2903,-2765,-2662,-2550,-2432,-2295,-2182,-2055,-1908,-1781,-1667,-1540,-1359,-1143,-968,-842,-809,-835,-873,-855,-795,-747,-766,-827,-929,-1096,-1281,-1468,-1631,-1727,-1781,-1793,-1759,-1637,-1473,-1277,-1106,-980,-913,-878,-823,-693,-453,-163,172,440,593,642,645,687,717,757,808,862,924,955,952,903,891,888,918,923,926,907,856,802,733,652,543,399,171,-136,-469,-796,-1082,-1343,-1569,-1790,-2012,-2209,-2421,-2641,-2863,-2991,-3023,-2983,-2899,-2797,-2734,-2721,-2761,-2795,-2819,-2830,-2834,-2853,-2906,-2910,-2868,-2781,-2657,-2482,-2265,-2045,-1828,-1597,-1378,-1166,-944,-703,-437,-222,-49,85,156,105,3,-80,-168,-239,-276,-307,-445,-474,-506,-506,-550,-610,-635,-653,-559,-477,-384,-300,-161};
  //int16_t wave_table[] = {16,270,524,728,917,1024,1075,1369,1567,1699,1830,1970,2169,2452,2822,3100,3279,3384,3388,3466,3530,3417,3171,2718,2248,1787,1445,1133,696,182,-303,-698,-825,-833,-937,-1119,-1315,-1403,-1342,-1165,-868,-553,-308,-105,132,379,709,1058,1380,1648,1866,2089,2333,2591,2833,3100,3330,3557,3848,4154,4375,4460,4462,4495,4585,4614,4541,4389,4118,3820,3554,3383,3283,3269,3388,3557,3685,3714,3690,3700,3854,4112,4416,4557,4490,4351,4245,4134,4024,3902,3727,3475,3203,2955,2740,2504,2261,1979,1680,1369,1031,628,92,-460,-961,-1379,-1742,-2088,-2428,-2794,-3162,-3438,-3559,-3559,-3520,-3544,-3687,-3855,-4000,-4095,-4168,-4283,-4341,-4333,-4214,-3990,-3730,-3463,-3167,-2877,-2569,-2219,-1887,-1658,-1529,-1602,-1759,-1940,-2125,-2248,-2427,-2590,-2713,-2824,-2949,-3036,-3045,-2984,-2929,-2854,-2664,-2438,-2240,-2080,-1901,-1800,-1753,-1449,-1226,-1047,-868,-691,-469,-168,222,531,752,901,943,1050,1141,1071,881,488,55,-402,-765,-1104,-1543,-2042,-2503,-2874,-2978,-2953,-3009,-3134,-3267,-3293,-3179,-2958,-2619,-2262,-1969,-1723,-1454,-1189,-850,-490,-153,122,328,515,715,935,1140,1368,1553,1744,2021,2319,2531,2602,2592,2628,2729,2775,2724,2594,2361,2110,1894,1768,1697,1703,1839,2026,2175,2228,2236,2284,2493,2819,3212,3460,3502,3470,3469,3468,3481,3497,3462,3343,3198,3067,2968,2849,2721,2553,2372,2180,1961,1673,1248,812,430,125,-127,-367,-599,-856,-1118,-1289,-1303,-1191,-1042,-960,-1007,-1090,-1158,-1192,-1211,-1277,-1290,-1244,-1110,-895,-665,-439,-184,64,331,642,939,1145,1267,1200,1061,910,757,669,527,407,345,308,260,246,299,413,513,625,845,1092,1307,1477,1647,1721,1723,1968,2127,2231,2328,2417,2550,2770,3090,3339,3510,3622,3646,3752,3854,3801,3629,3255,2843,2414,2086,1784,1372,883,412,15,-134,-175,-311,-528,-757,-885,-876,-754,-505,-231,-17,149,341,536,809,1110,1391,1616,1778,1923,2078,2249,2403,2585,2726,2867,3085,3316,3462,3472,3394,3355,3373,3328,3188,2972,2656,2326,2033,1832,1695,1641,1722,1853,1941,1924,1859,1828,1953,2196,2494,2643,2587,2458,2366,2278,2204,2140,2037,1858,1659,1480,1337,1182,1022,819,599,362,86,-266,-768,-1296,-1785,-2207,-2584,-2948,-3300,-3671,-4036,-4296,-4393,-4361,-4288,-4275,-4370,-4484,-4576,-4625,-4653,-4719,-4724,-4672,-4531,-4304,-4060,-3821,-3561,-3316,-3056,-2754,-2470,-2283,-2189,-2289,-2464,-2653,-2847,-2985,-3179,-3349,-3462,-3546,-3637,-3686,-3660,-3573,-3501,-3409,-3192,-2937,-2712,-2532,-2346,-2239,-2194,-1910,-1718,-1585,-1460,-1345,-1198,-975,-660,-422,-267,-180,-195,-138,-94,-212,-450,-890,-1368,-1868,-2272,-2647,-3121,-3657,-4168,-4602,-4778,-4825,-4953,-5147,-5345,-5433,-5376,-5208,-4918,-4601,-4340,-4116,-3860,-3596,-3248,-2867,-2504,-2196,-1950,-1717,-1472,-1216,-985,-731,-512,-283,32,364,608,716,748,830,975,1054,1027,922,720,506,331,248,227,290,488,739,947,1042,1075,1134,1349,1681,2065,2291,2307,2253,2229,2188,2145,2106,2024,1865,1680,1514,1394,1261,1114,924,720,506,260,-68,-539,-1017,-1438,-1775,-2055,-2320,-2578,-2870,-3179,-3383,-3405,-3282,-3113,-3021,-3053,-3098,-3115,-3085,-3047,-3063,-3020,-2918,-2723,-2453,-2175,-1893,-1580,-1275,-964,-623,-287,-22,164,156,62,-53,-158,-203,-312,-413,-480,-526,-588,-610,-558,-445,-322,-193};
  int16_t wave_table[] = {8, 86, 173, 266, 361, 457, 550, 635, 712, 772, 816, 844, 852, 848, 832, 812, 796, 782, 781, 790, 809, 838, 874, 916, 959, 1005, 1049, 1092, 1134, 1170, 1204, 1230, 1247, 1253, 1246, 1227, 1196, 1154, 1103, 1046, 988, 927, 871, 825, 795, 784, 800, 849, 929, 1044, 1192, 1367, 1566, 1779, 1998, 2217, 2428, 2624, 2800, 2951, 3069, 3152, 3199, 3206, 3178, 3116, 3023, 2906, 2768, 2617, 2458, 2294, 2131, 1972, 1823, 1686, 1560, 1446, 1341, 1246, 1155, 1064, 970, 868, 758, 637, 506, 371, 234, 105, -7, -97, -156, -179, -159, -96, 8, 149, 319, 514, 721, 933, 1143, 1343, 1527, 1692, 1834, 1952, 2045, 2110, 2148, 2160, 2144, 2103, 2037, 1946, 1836, 1707, 1564, 1410, 1250, 1090, 932, 781, 637, 501, 375, 252, 131, 8, -120, -253, -392, -536, -684, -836, -989, -1144, -1297, -1447, -1593, -1728, -1856, -1972, -2074, -2163, -2236, -2296, -2338, -2363, -2370, -2361, -2337, -2300, -2254, -2207, -2157, -2109, -2062, -2016, -1970, -1922, -1872, -1821, -1769, -1718, -1669, -1619, -1568, -1513, -1449, -1371, -1276, -1163, -1028, -870, -696, -504, -299, -86, 129, 344, 554, 748, 927, 1084, 1214, 1318, 1389, 1432, 1446, 1433, 1399, 1347, 1286, 1221, 1157, 1099, 1050, 1012, 983, 962, 953, 954, 966, 989, 1021, 1060, 1104, 1150, 1195, 1239, 1284, 1331, 1386, 1453, 1534, 1632, 1747, 1876, 2013, 2148, 2276, 2388, 2478, 2545, 2583, 2595, 2580, 2538, 2474, 2387, 2278, 2153, 2011, 1858, 1695, 1529, 1371, 1222, 1088, 972, 874, 796, 734, 685, 652, 628, 618, 625, 646, 684, 736, 798, 866, 937, 1005, 1066, 1119, 1163, 1200, 1227, 1245, 1253, 1249, 1232, 1199, 1154, 1097, 1029, 954, 877, 800, 722, 647, 575, 503, 434, 365, 298, 232, 166, 105, 49, -2, -48, -91, -131, -169, -208, -243, -273, -299, -316, -320, -313, -293, -263, -228, -195, -167, -146, -135, -131, -136, -144, -155, -168, -186, -215, -256, -316, -397, -503, -635, -786, -957, -1136, -1316, -1494, -1655, -1800, -1918, -2007, -2069, -2097, -2099, -2073, -2027, -1968, -1904, -1842, -1786, -1741, -1704, -1674, -1648, -1621, -1593, -1561, -1525, -1489, -1453, -1423, -1400, -1387, -1385, -1391, -1408, -1434, -1470, -1516, -1568, -1623, -1676, -1719, -1747, -1750, -1725, -1669, -1579, -1456, -1300, -1118, -919, -709, -504, -309, -131, 24, 160, 273, 368, 445, 508, 559, 596, 620, 630, 627, 610, 574, 520, 448, 354, 238, 101, -52, -221, -399, -578, -750, -906, -1040, -1144, -1217, -1258, -1265, -1245, -1198, -1127, -1041, -937, -820, -692, -553, -405, -246, -78, 101, 286, 476, 672, 869, 1067, 1261, 1447, 1621, 1775, 1902, 1996, 2054, 2073, 2053, 2001, 1920, 1817, 1706, 1591, 1483, 1389, 1312, 1254, 1213, 1189, 1183, 1189, 1207, 1232, 1262, 1293, 1325, 1354, 1382, 1412, 1448, 1492, 1549, 1619, 1699, 1789, 1880, 1967, 2044, 2105, 2144, 2159, 2151, 2119, 2064, 1992, 1903, 1801, 1689, 1570, 1447, 1319, 1187, 1055, 920, 781, 639, 495, 349, 207, 68, -66, -191, -304, -405, -491, -562, -619, -662, -699, -730, -757, -786, -816, -852, -897, -952, -1021, -1104, -1201, -1312, -1436, -1568, -1707, -1849, -1988, -2119, -2240, -2349, -2447, -2533, -2609, -2679, -2745, -2809, -2877, -2945, -3013, -3082, -3145, -3200, -3243, -3268, -3276, -3259, -3214, -3139, -3032, -2891, -2720, -2523, -2304, -2077, -1848, -1623, -1414, -1223, -1055, -914, -802, -726, -683, -674, -701, -760, -849, -961, -1096, -1247, -1409, -1580, -1753, -1924, -2083, -2227, -2351, -2448, -2520, -2567, -2589, -2593, -2583, -2563, -2537, -2508, -2477, -2448, -2421, -2394, -2369, -2346, -2321, -2291, -2256, -2214, -2161, -2100, -2029, -1949, -1857, -1758, -1650, -1532, -1409, -1279, -1144, -1006, -870, -741, -619, -516, -431, -369, -331, -312, -315, -327, -344, -358, -359, -345, -308, -252, -169, -69};

  // Enable transmission
  NRF_I2S->CONFIG.TXEN = (I2S_CONFIG_TXEN_TXEN_ENABLE << I2S_CONFIG_TXEN_TXEN_Pos);
  
  // Enable MCK generator
  NRF_I2S->CONFIG.MCKEN = (I2S_CONFIG_MCKEN_MCKEN_ENABLE << I2S_CONFIG_MCKEN_MCKEN_Pos);
  
  // MCKFREQ = 4 MHz
  NRF_I2S->CONFIG.MCKFREQ = I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV11  << I2S_CONFIG_MCKFREQ_MCKFREQ_Pos;
  
  // Ratio = 64 
  NRF_I2S->CONFIG.RATIO = I2S_CONFIG_RATIO_RATIO_64X << I2S_CONFIG_RATIO_RATIO_Pos;
    
  // Master mode, 16Bit, left aligned
  NRF_I2S->CONFIG.MODE = I2S_CONFIG_MODE_MODE_MASTER << I2S_CONFIG_MODE_MODE_Pos;
  NRF_I2S->CONFIG.SWIDTH = I2S_CONFIG_SWIDTH_SWIDTH_16BIT << I2S_CONFIG_SWIDTH_SWIDTH_Pos;
  NRF_I2S->CONFIG.ALIGN = I2S_CONFIG_ALIGN_ALIGN_LEFT << I2S_CONFIG_ALIGN_ALIGN_Pos;
  
  // Format = I2S
  NRF_I2S->CONFIG.FORMAT = I2S_CONFIG_FORMAT_FORMAT_I2S << I2S_CONFIG_FORMAT_FORMAT_Pos;
  
  // Use stereo 
  NRF_I2S->CONFIG.CHANNELS = I2S_CONFIG_CHANNELS_CHANNELS_LEFT << I2S_CONFIG_CHANNELS_CHANNELS_Pos;
  
  // Configure pins
  NRF_I2S->PSEL.MCK = (PIN_MCK << I2S_PSEL_MCK_PIN_Pos);
  NRF_I2S->PSEL.SCK = (PIN_SCK << I2S_PSEL_SCK_PIN_Pos); 
  NRF_I2S->PSEL.LRCK = (PIN_LRCK << I2S_PSEL_LRCK_PIN_Pos); 
  NRF_I2S->PSEL.SDOUT = (PIN_SDOUT << I2S_PSEL_SDOUT_PIN_Pos);
  
  NRF_I2S->ENABLE = 1;
  
  // Configure data pointer
  NRF_I2S->TXD.PTR = (uint32_t)&wave_table[0];
  NRF_I2S->RXTXD.MAXCNT = sizeof(wave_table) / sizeof(uint32_t);
  
  // Start transmitting I2S data
  NRF_I2S->TASKS_START = 1;
  
  
  // Since we are not updating the TXD pointer, the sine wave will play over and over again.
  // The TXD pointer can be updated after the EVENTS_TXPTRUPD arrives.
  while (1)
  {
    __WFE();
  }
}
