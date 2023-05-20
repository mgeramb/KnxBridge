#pragma once

// Parameter with single occurrence
#define DeviceStartTime            0      // int32_t
#define BridgeName                 4      // char*, 25 Byte
#define Modus                     29      // 8 Bits, Bit 7-0
#define WiFiSSID                  30      // char*, 32 Byte
#define WiFiPassword              62      // char*, 64 Byte
#define PairingCode               126      // char*, 8 Byte
#define Device1Type               134      // 8 Bits, Bit 7-0
#define Device1Name               135      // char*, 25 Byte
#define Device2Type               160      // 8 Bits, Bit 7-0
#define Device2Name               161      // char*, 25 Byte
#define Device3Type               186      // 8 Bits, Bit 7-0
#define Device3Name               187      // char*, 25 Byte
#define Device4Type               212      // 8 Bits, Bit 7-0
#define Device4Name               213      // char*, 25 Byte
#define Device5Type               238      // 8 Bits, Bit 7-0
#define Device5Name               239      // char*, 25 Byte
#define Device6Type               264      // 8 Bits, Bit 7-0
#define Device6Name               265      // char*, 25 Byte
#define Device7Type               290      // 8 Bits, Bit 7-0
#define Device7Name               291      // char*, 25 Byte
#define Device8Type               316      // 8 Bits, Bit 7-0
#define Device8Name               317      // char*, 25 Byte
#define Device9Type               342      // 8 Bits, Bit 7-0
#define Device9Name               343      // char*, 25 Byte
#define Device10Type              368      // 8 Bits, Bit 7-0
#define Device10Name              369      // char*, 25 Byte
#define Device11Type              394      // 8 Bits, Bit 7-0
#define Device11Name              395      // char*, 25 Byte
#define Device12Type              420      // 8 Bits, Bit 7-0
#define Device12Name              421      // char*, 25 Byte
#define Device13Type              446      // 8 Bits, Bit 7-0
#define Device13Name              447      // char*, 25 Byte
#define Device14Type              472      // 8 Bits, Bit 7-0
#define Device14Name              473      // char*, 25 Byte
#define Device15Type              498      // 8 Bits, Bit 7-0
#define Device15Name              499      // char*, 25 Byte
#define Device16Type              524      // 8 Bits, Bit 7-0
#define Device16Name              525      // char*, 25 Byte
#define Device17Type              550      // 8 Bits, Bit 7-0
#define Device17Name              551      // char*, 25 Byte
#define Device18Type              576      // 8 Bits, Bit 7-0
#define Device18Name              577      // char*, 25 Byte
#define Device19Type              602      // 8 Bits, Bit 7-0
#define Device19Name              603      // char*, 25 Byte
#define Device20Type              628      // 8 Bits, Bit 7-0
#define Device20Name              629      // char*, 25 Byte
#define Device21Type              654      // 8 Bits, Bit 7-0
#define Device21Name              655      // char*, 25 Byte
#define Device22Type              680      // 8 Bits, Bit 7-0
#define Device22Name              681      // char*, 25 Byte
#define Device23Type              706      // 8 Bits, Bit 7-0
#define Device23Name              707      // char*, 25 Byte
#define Device24Type              732      // 8 Bits, Bit 7-0
#define Device24Name              733      // char*, 25 Byte
#define Device25Type              758      // 8 Bits, Bit 7-0
#define Device25Name              759      // char*, 25 Byte
#define _Device26Type             784      // 8 Bits, Bit 7-0
#define _Device26Name             785      // char*, 25 Byte
#define _Device27Type             810      // 8 Bits, Bit 7-0
#define _Device27Name             811      // char*, 25 Byte
#define _Device28Type             836      // 8 Bits, Bit 7-0
#define _Device28Name             837      // char*, 25 Byte
#define _Device29Type             862      // 8 Bits, Bit 7-0
#define _Device29Name             863      // char*, 25 Byte
#define Device30Type              888      // 8 Bits, Bit 7-0
#define Device30Name              889      // char*, 25 Byte
#define Device31Type              914      // 8 Bits, Bit 7-0
#define Device31Name              915      // char*, 25 Byte
#define Device32Type              940      // 8 Bits, Bit 7-0
#define Device32Name              941      // char*, 25 Byte
#define Device33Type              966      // 8 Bits, Bit 7-0
#define Device33Name              967      // char*, 25 Byte
#define Device34Type              992      // 8 Bits, Bit 7-0
#define Device34Name              993      // char*, 25 Byte
#define Device35Type              1018      // 8 Bits, Bit 7-0
#define Device35Name              1019      // char*, 25 Byte
#define Device36Type              1044      // 8 Bits, Bit 7-0
#define Device36Name              1045      // char*, 25 Byte
#define Device37Type              1070      // 8 Bits, Bit 7-0
#define Device37Name              1071      // char*, 25 Byte
#define Device38Type              1096      // 8 Bits, Bit 7-0
#define Device38Name              1097      // char*, 25 Byte
#define Device39Type              1122      // 8 Bits, Bit 7-0
#define Device39Name              1123      // char*, 25 Byte
#define Device40Type              1148      // 8 Bits, Bit 7-0
#define Device40Name              1149      // char*, 25 Byte
#define Device41Type              1174      // 8 Bits, Bit 7-0
#define Device41Name              1175      // char*, 25 Byte

// Communication objects with single occurrence
#define KoWLAN_Status 1
#define KoGerät_1_Schalten 2
#define KoGerät_1_Schalten_Rückmeldung 3
#define KoGerät_1_Dimmer 4
#define KoGerät_1_Dimmer_Rückmeldung 5
#define KoGerät_2_Schalten 6
#define KoGerät_2_Schalten_Rückmeldung 7
#define KoGerät_2_Dimmer 8
#define KoGerät_2_Dimmer_Rückmeldung 9
#define KoGerät_3_Schalten 10
#define KoGerät_3_Schalten_Rückmeldung 11
#define KoGerät_3_Dimmer 12
#define KoGerät_3_Dimmer_Rückmeldung 13
#define KoGerät_4_Schalten 14
#define KoGerät_4_Schalten_Rückmeldung 15
#define KoGerät_4_Dimmer 16
#define KoGerät_4_Dimmer_Rückmeldung 17
#define KoGerät_5_Schalten 18
#define KoGerät_5_Schalten_Rückmeldung 19
#define KoGerät_5_Dimmer 20
#define KoGerät_5_Dimmer_Rückmeldung 21
#define KoGerät_6_Schalten 22
#define KoGerät_6_Schalten_Rückmeldung 23
#define KoGerät_6_Dimmer 24
#define KoGerät_6_Dimmer_Rückmeldung 25
#define KoGerät_7_Schalten 26
#define KoGerät_7_Schalten_Rückmeldung 27
#define KoGerät_7_Dimmer 28
#define KoGerät_7_Dimmer_Rückmeldung 29
#define KoGerät_8_Schalten 30
#define KoGerät_8_Schalten_Rückmeldung 31
#define KoGerät_8_Dimmer 32
#define KoGerät_8_Dimmer_Rückmeldung 33
#define KoGerät_9_Schalten 34
#define KoGerät_9_Schalten_Rückmeldung 35
#define KoGerät_9_Dimmer 36
#define KoGerät_9_Dimmer_Rückmeldung 37
#define KoGerät_10_Schalten 38
#define KoGerät_10_Schalten_Rückmeldung 39
#define KoGerät_10_Dimmer 40
#define KoGerät_10_Dimmer_Rückmeldung 41
#define KoGerät_11_Schalten 42
#define KoGerät_11_Schalten_Rückmeldung 43
#define KoGerät_11_Dimmer 44
#define KoGerät_11_Dimmer_Rückmeldung 45
#define KoGerät_12_Schalten 46
#define KoGerät_12_Schalten_Rückmeldung 47
#define KoGerät_12_Dimmer 48
#define KoGerät_12_Dimmer_Rückmeldung 49
#define KoGerät_13_Schalten 50
#define KoGerät_13_Schalten_Rückmeldung 51
#define KoGerät_13_Dimmer 52
#define KoGerät_13_Dimmer_Rückmeldung 53
#define KoGerät_14_Schalten 54
#define KoGerät_14_Schalten_Rückmeldung 55
#define KoGerät_14_Dimmer 56
#define KoGerät_14_Dimmer_Rückmeldung 57
#define KoGerät_15_Schalten 58
#define KoGerät_15_Schalten_Rückmeldung 59
#define KoGerät_15_Dimmer 60
#define KoGerät_15_Dimmer_Rückmeldung 61
#define KoGerät_16_Schalten 62
#define KoGerät_16_Schalten_Rückmeldung 63
#define KoGerät_16_Dimmer 64
#define KoGerät_16_Dimmer_Rückmeldung 65
#define KoGerät_17_Schalten 66
#define KoGerät_17_Schalten_Rückmeldung 67
#define KoGerät_17_Dimmer 68
#define KoGerät_17_Dimmer_Rückmeldung 69
#define KoGerät_18_Schalten 70
#define KoGerät_18_Schalten_Rückmeldung 71
#define KoGerät_18_Dimmer 72
#define KoGerät_18_Dimmer_Rückmeldung 73
#define KoGerät_19_Schalten 74
#define KoGerät_19_Schalten_Rückmeldung 75
#define KoGerät_19_Dimmer 76
#define KoGerät_19_Dimmer_Rückmeldung 77
#define KoGerät_20_Schalten 78
#define KoGerät_20_Schalten_Rückmeldung 79
#define KoGerät_20_Dimmer 80
#define KoGerät_20_Dimmer_Rückmeldung 81
#define KoGerät_21_Schalten 82
#define KoGerät_21_Schalten_Rückmeldung 83
#define KoGerät_21_Dimmer 84
#define KoGerät_21_Dimmer_Rückmeldung 85
#define KoGerät_22_Schalten 86
#define KoGerät_22_Schalten_Rückmeldung 87
#define KoGerät_22_Dimmer 88
#define KoGerät_22_Dimmer_Rückmeldung 89
#define KoGerät_23_Schalten 90
#define KoGerät_23_Schalten_Rückmeldung 91
#define KoGerät_23_Dimmer 92
#define KoGerät_23_Dimmer_Rückmeldung 93
#define KoGerät_24_Schalten 94
#define KoGerät_24_Schalten_Rückmeldung 95
#define KoGerät_24_Dimmer 96
#define KoGerät_24_Dimmer_Rückmeldung 97
#define KoGerät_25_Schalten 98
#define KoGerät_25_Schalten_Rückmeldung 99
#define KoGerät_25_Dimmer 100
#define KoGerät_25_Dimmer_Rückmeldung 101
#define KoGerät_26_Schalten 102
#define KoGerät_26_Schalten_Rückmeldung 103
#define KoGerät_26_Dimmer 104
#define KoGerät_26_Dimmer_Rückmeldung 105
#define KoGerät_27_Schalten 106
#define KoGerät_27_Schalten_Rückmeldung 107
#define KoGerät_27_Dimmer 108
#define KoGerät_27_Dimmer_Rückmeldung 109
#define KoGerät_28_Schalten 110
#define KoGerät_28_Schalten_Rückmeldung 111
#define KoGerät_28_Dimmer 112
#define KoGerät_28_Dimmer_Rückmeldung 113
#define KoGerät_29_Schalten 114
#define KoGerät_29_Schalten_Rückmeldung 115
#define KoGerät_29_Dimmer 116
#define KoGerät_29_Dimmer_Rückmeldung 117
#define KoGerät_30_Schalten 118
#define KoGerät_30_Schalten_Rückmeldung 119
#define KoGerät_30_Dimmer 120
#define KoGerät_30_Dimmer_Rückmeldung 121
#define KoGerät_31_Schalten 122
#define KoGerät_31_Schalten_Rückmeldung 123
#define KoGerät_31_Dimmer 124
#define KoGerät_31_Dimmer_Rückmeldung 125
#define KoGerät_32_Schalten 126
#define KoGerät_32_Schalten_Rückmeldung 127
#define KoGerät_32_Dimmer 128
#define KoGerät_32_Dimmer_Rückmeldung 129
#define KoGerät_33_Schalten 130
#define KoGerät_33_Schalten_Rückmeldung 131
#define KoGerät_33_Dimmer 132
#define KoGerät_33_Dimmer_Rückmeldung 133
#define KoGerät_34_Schalten 134
#define KoGerät_34_Schalten_Rückmeldung 135
#define KoGerät_34_Dimmer 136
#define KoGerät_34_Dimmer_Rückmeldung 137
#define KoGerät_35_Schalten 138
#define KoGerät_35_Schalten_Rückmeldung 139
#define KoGerät_35_Dimmer 140
#define KoGerät_35_Dimmer_Rückmeldung 141
#define KoGerät_36_Schalten 142
#define KoGerät_36_Schalten_Rückmeldung 143
#define KoGerät_36_Dimmer 144
#define KoGerät_36_Dimmer_Rückmeldung 145
#define KoGerät_37_Schalten 146
#define KoGerät_37_Schalten_Rückmeldung 147
#define KoGerät_37_Dimmer 148
#define KoGerät_37_Dimmer_Rückmeldung 149
#define KoGerät_38_Schalten 150
#define KoGerät_38_Schalten_Rückmeldung 151
#define KoGerät_38_Dimmer 152
#define KoGerät_38_Dimmer_Rückmeldung 153
#define KoGerät_39_Schalten 154
#define KoGerät_39_Schalten_Rückmeldung 155
#define KoGerät_39_Dimmer 156
#define KoGerät_39_Dimmer_Rückmeldung 157
#define KoGerät_40_Schalten 158
#define KoGerät_40_Schalten_Rückmeldung 159
#define KoGerät_40_Dimmer 160
#define KoGerät_40_Dimmer_Rückmeldung 161
#define KoGerät_41_Schalten 162
#define KoGerät_41_Schalten_Rückmeldung 163
#define KoGerät_41_Dimmer 164
#define KoGerät_41_Dimmer_Rückmeldung 165

