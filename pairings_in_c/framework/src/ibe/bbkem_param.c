/****************************************************************************
**
** Copyright (C) 2015 Stiftung Secure Information and
**                    Communication Technologies SIC and
**                    Graz University of Technology
** Contact: http://opensource.iaik.tugraz.at
**
**
** Commercial License Usage
** Licensees holding valid commercial licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and SIC. For further information
** contact us at http://opensource.iaik.tugraz.at.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** This software is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this software. If not, see http://www.gnu.org/licenses/.
**
**
****************************************************************************/

#include "ibe/bbkem.h"

#if (BNCURVE == BN256)
#ifdef MONTGOMERY_ARITHMETIC
const bbkem_public BB1_PUBLIC = { { {0x9DD3CB65, 0x0111764E, 0x2B8820B9,
			0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D}, {
			0x3BA796CA, 0x0222EC9D, 0x57104172, 0xD9DCA6BE, 0x583AEC95, 0x093F4729,
			0x7FC247AE, 0x8BD8C27B}, 0}, { {0x16AC9311, 0x7AB900B0, 0x9FFCC238,
			0x50FD8D4D, 0x52BE69E8, 0x092B320B, 0x3EEF2D02, 0x96F24818}, {
			0xCBC85FE0, 0xCE889BE6, 0xD105F307, 0x166CC1B9, 0x310CEBC2, 0x52D40FA2,
			0xD189C7F1, 0x481903DC}, 0}, { {0xDCDD3235, 0xEE2EDEA7, 0xFE9E6016,
			0x2A5AC382, 0x45A89766, 0x72C03D1D, 0xC0F8CA5E, 0x9EC52516}, {
			0x96A4DDFC, 0xEDBAF505, 0x3BFBEF49, 0x1BD3DDF8, 0xB0887FD3, 0xFB279106,
			0x894AB66E, 0x30302588}, 0}, { { {
				{	0x7C253AC6, 0x2A82357B, 0xCC329883, 0x2AB69374, 0xE2706EC4,
					0x10E7561E, 0x8136E062, 0x8D7323BE}, {0x4B30965E, 0x781CED66,
					0x9B39E29E, 0x5999F4AF, 0xD65B7823, 0x9D97396F, 0xB1BEDB6E,
					0xB1BD6A1B}}, { {0xF61E7523, 0x80C7E299, 0xDE50DEA3,
					0xDCBE9A66, 0xC18D6D0F, 0x39A7034F, 0x5C60D3DF, 0x849714CD}, {
					0xFEA65588, 0x4F93432E, 0x10E4AA2F, 0xD2CD73CF, 0xE3BD4220, 0x97357B35,
					0x9411C872, 0x9F60211C}}}, { { {0xDDCEEA3E, 0x60578B46, 0x0C02158D,
					0x6B902AA4, 0x0DDCD1B1, 0x5E373ABF, 0x9A76F141, 0x6DED84DB}, {
					0x33713D46, 0xE6ADAB2C, 0x7BCD38CD, 0x26B93D34, 0x5A302C6B, 0x28F645ED,
					0x263B38F5, 0x55E8B60B}}, { {0x87DA2253, 0xB369D986, 0x6828ED40,
					0x7702DEAD, 0x8DB79097, 0xFA6C3782, 0x05E054CE, 0x3D8C4FC1}, {
					0x3ECEFFD4, 0x62F9961D, 0x58E1A67D, 0x42F6B211, 0x6CB4546E, 0x6DFAC0C2,
					0x1F994749, 0x573DE2C6}}}, { { {0xA5B9ECBB, 0x550BD754, 0x61327D81,
					0x923B7F4E, 0xC4A1FBD5, 0xB602EEB8, 0xA2713B35, 0xA2450255}, {
					0x08A9AE31, 0x2055416E, 0x57F48086, 0x79FBC8A6, 0x52DE6DF7, 0x0B240130,
					0x2C26E151, 0x4FA25C81}}, { {0x761F87F2, 0x47C97207, 0xED1D4F5D,
					0xF0F77C2D, 0x751539A9, 0xBD22192E, 0xA7DA76BD, 0x270C7A0F}, {
					0x42B2C4CC, 0x913CB203, 0x9E6C4EF9, 0xB69DF930, 0x1D2033E2, 0xB628BD7B,
					0xD17A9165, 0x7B4B8341}}}}};

const bbkem_pk BB1_PK = { { { {0x2A32750E, 0x39098E10, 0xEDB85167, 0x3AECA4DB,
				0x897DA017, 0xFF0F80C4, 0xA9AC5387, 0xB085C3DC}, {0x2ED14CE8,
				0x99810355, 0x6C74F926, 0x6ED7E30B, 0x9BB6E928, 0x2E016F33, 0x7ADE4104,
				0x48DB16DF}}, { {0x6461BA24, 0x737F0158, 0xC8BF8C1C, 0x48AF5ECE,
				0x59319EEF, 0x22E24E90, 0x9BF2F00F, 0x24C3F5C9}, {0x804ECA07,
				0xDB56E859, 0xA7ACCEE6, 0xFE20D267, 0x7274AAA8, 0x24DA6FDF, 0x2E073C57,
				0x419AB487}}, 0}, { { {0x5F7664FB, 0x6551C433, 0x23D1FDB3,
				0x1A346A31, 0xE62F7DA3, 0x1938FA3E, 0xD2C31DAA, 0x5C5E6EF3}, {
				0x8ACAF3E3, 0xAB16EFD5, 0xC608A284, 0xEAB69C41, 0xBBA01884, 0x794D65EA,
				0x995B1E1B, 0x209577C6}}, { {0x4E8706F6, 0xF66DD24F, 0x7F896365,
				0xFABBF6F8, 0x4F45F518, 0x49EA0E85, 0x65CBD409, 0x07B04183}, {
				0x384E7BD3, 0x57A0A3B4, 0x772B9784, 0xEF1126FC, 0x38C127D2, 0x798D82A5,
				0x71586EE5, 0x8FDD4C2C}}, 0}};
#else

const bbkem_public BB1_PUBLIC = { { {0x00000001, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000}, {0x00000002,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000}, 0}, { {0xCBF0735F, 0xCF5A04A5, 0x15C8A907, 0xECC2494D,
			0x9B323EF9, 0xD5EFFAEA, 0xDA27B921, 0xA7C12746}, {0xD5FAD3CC,
			0xAED8C7C8, 0x6F6738B7, 0xF532C9F4, 0xC37518DC, 0x7EC91769, 0x549152F4,
			0x6C8C96BC}, 0}, { {0x13F45AB5, 0x931ED655, 0x4E063E3C, 0x8BBF03AB,
			0xA9CA6163, 0x9266D120, 0xF5C67575, 0xA4D3269D}, {0xD5921B0D,
			0xA3978027, 0xDED3BA51, 0xB1FF7F72, 0xAE1C8B51, 0x71D07630, 0x5372D9D5,
			0x031590AB}, 0}, { { { {0x3E86D652, 0xFD6F2F89, 0x7891C14A,
					0x8C8E248A, 0x1E440DDF, 0x0181DC57, 0xDB1AAB1D, 0x09E98754}, {
					0xEF5FAA0B, 0x64A01F80, 0x3173CB95, 0x7314FC18, 0x8D760747, 0x4E7C7B78,
					0x0F5F280B, 0x1E1C311D}}, { {0xC7FFCABB, 0xC8182A56, 0x7E4AC991,
					0x1F79EEB4, 0x1D65F419, 0xF034DEAF, 0x37F679AA, 0x495614E3}, {
					0xF137275B, 0x7CED5C47, 0xF74993EB, 0x361600E0, 0xC09DD1E8, 0x57FD81E7,
					0xD389B946, 0xB0A8EC04}}}, { { {0x474D32BB, 0xDB7A0C9F, 0x7BDFE87B,
					0x76D84B9C, 0xA7F61311, 0x8AC64A8E, 0xECE786BF, 0x24798EA9}, {
					0xB1682988, 0x451BC7FC, 0x96F3EC9C, 0xEFB185EE, 0xE155DED1, 0x2DD30A6C,
					0x71E32F3E, 0x5650137E}}, { {0xD2BB8B0F, 0xFF4DC97D, 0xEDB9BB64,
					0xA7E4E545, 0x19BA7FEA, 0xBDB1E017, 0xEB9D6862, 0xB1174FE3}, {
					0xB9B1C551, 0xE0CE890D, 0xF947E6A0, 0xE2258B78, 0x27463981, 0x59FF383D,
					0x3167BF00, 0x79D352AC}}}, { { {0xF78CC71D, 0x7361AF5A, 0xBF52263B,
					0xF183652F, 0xAB3CF155, 0xB8769251, 0xD1DC4307, 0x3FAD2C68}, {
					0x2EEEB953, 0xC4427832, 0x30BAB6B6, 0xDE7337B8, 0x10C86BB3, 0xDCAE4BAD,
					0x114AF210, 0x99E18263}}, { {0x105146F0, 0x3E788C3E, 0x7FD61A73,
					0x94082CD0, 0x7A5E7190, 0x473DFB4A, 0xCABD8FBE, 0xB3CAD311}, {
					0xCBFC7CD4, 0xEC52DC9C, 0xBFAB80B5, 0x26F4D290, 0x5EF31608, 0x0AAD18E0,
					0x11BDCD80, 0x95B0EC06}}}}};

const bbkem_pk BB1_PK = { { { {0x4D5553A7, 0x7EE36D1E, 0xF5C29373, 0x8CC29E22,
				0x6B236703, 0xEFD88202, 0xCBAB1A16, 0x6CAA0EA5}, {0x4182F388,
				0x69EB1456, 0x9CC4DDC7, 0xBD05257A, 0x947CFA6C, 0x0EA3B327, 0x0F5A2010,
				0x0B4007AF}}, { {0x0C7D4BDC, 0x2DF763BA, 0xE930C121, 0x980A7C72,
				0x60CE95EC, 0x66742B12, 0xF4C95F9A, 0x06164829}, {0xC3EBB8F4,
				0xF587DA4D, 0x2BB82274, 0x70D88E67, 0xA7399E81, 0xD1A62A2F, 0x4FAAE595,
				0xB21BDB8C}}, 0}, { { {0x1BDC9D0D, 0xFBFA7397, 0xB5ADCA2A,
				0x0268348E, 0x2E81A3F4, 0x500B2BD9, 0x5D1730C0, 0x978FD01F}, {
				0x130766B1, 0xC57DF4AC, 0x07A72992, 0x6F99EE33, 0xE74FE14B, 0x8EC62EBA,
				0x30CEF1DE, 0x03FB3C5E}}, { {0x1A421339, 0xBC733A38, 0xB317F5BC,
				0x8AF6F49D, 0x5704B631, 0xF7EAB519, 0x9B92FE8A, 0x83192775}, {
				0x88487D44, 0xB217DBE3, 0x2F9D3B1D, 0x26BAF31B, 0xD1F5553D, 0xB0437121,
				0xA3DB518E, 0xB15AD688}}, 0}};

#endif
#elif (BNCURVE == BN254)
#ifdef MONTGOMERY_ARITHMETIC
const bbkem_public BB1_PUBLIC = { { {0x00000085, 0x91000000, 0x00000089,
			0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F}, {
			0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF,
			0x7FFFFFF5, 0x212BA4F2}, 0}, { {0x0663B49C, 0x19AD1735, 0xD0549011,
			0x8C6FED8C, 0x34333943, 0xA5765D45, 0x34122C6A, 0x16F29F24}, {
			0xBCED475B, 0xE9A1E472, 0xD898FF87, 0xA8F414D1, 0x0ECF60F2, 0xBCDB4AD1,
			0x58617D99, 0x00BEAF21}, 0}, { {0x49740CD4, 0x493E9505, 0x24D80930,
			0xBBCEC03B, 0x22433D4C, 0xAFE73D12, 0xAB02D620, 0x1A32F0A9}, {
			0xEAB18E47, 0x24F6E6D1, 0xBDD686F5, 0x2D027904, 0xA3D1816C, 0x10FB00E4,
			0x1346C8C2, 0x108A2232}, 0}, { { {
				{	0x506E8D41, 0xC6399F45, 0xA0ABD023, 0x992E6B7F, 0xE0B95AF9,
					0xFE126581, 0xDA6E13E5, 0x184AE71E}, {0x9A9371CF, 0xE812711E,
					0x3A18AB3D, 0x0996C393, 0xA06C0106, 0x44DB44C5, 0x0434FFD2,
					0x23F66F24}}, { {0x50E33BE4, 0xCA8568C9, 0x06AC809F,
					0xFF681B20, 0x56C9116F, 0x2F20E0F9, 0x11EC8159, 0x1CA3DCEC}, {
					0x024BF1B7, 0xB5C296A8, 0x9473E268, 0x62AEBFC8, 0xB078882A, 0x560A4F95,
					0x125DF21C, 0x1CE8A5DF}}}, { { {0xF237FB18, 0x18D11D87, 0x668D5957,
					0xFA32CFD8, 0x2349707F, 0x9A712966, 0x42E8B9C6, 0x03050B18}, {
					0x5AC56E90, 0x3D057025, 0xF97E3F2D, 0xE99948FE, 0xD2223E58, 0xC87579CC,
					0x7DF47BA3, 0x0D5ABB14}}, { {0x81A61BD1, 0x50D181AC, 0x600A571F,
					0xC2E0DB56, 0xE12C7770, 0x90C4404B, 0xDE3EE77F, 0x1E1624B0}, {
					0x4B50E8B9, 0x56C12C0D, 0xEC91CB3B, 0x59A684D5, 0x07B0D6F0, 0xAAF99A9A,
					0xDFFFC284, 0x0D1025A8}}}, { { {0x016992C1, 0x572E6364, 0xB99AF23D,
					0x69E7E8BA, 0x8E3D0B13, 0xBB225773, 0xE6E9FC56, 0x178DE9E2}, {
					0x61BC0DD8, 0xFC7572FD, 0x08987D3C, 0x2E67F894, 0x130E302C, 0xA2701809,
					0x8FFA788D, 0x1ADC1674}}, { {0x119073D8, 0x5D7D8A68, 0x1F826E73,
					0x1D23D902, 0xEC5E914E, 0x50BC4294, 0x64E72F0A, 0x2152F214}, {
					0x5889F8D6, 0xDAF39F15, 0x41481F67, 0x7F0617C3, 0x92B6F92A, 0x31CEC072,
					0x52922C60, 0x0136C9BF}}}}};

const bbkem_pk BB1_PK = { { { {0xE72C0863, 0xD4A7D4FE, 0xAD16B778, 0xC7FEA6BD,
				0x3F2FED95, 0x109B81B4, 0x20FDEDCA, 0x1A5863A8}, {0xC6479F3B,
				0xC8EAB428, 0x89394C2A, 0xD4E90135, 0x24BE6868, 0x9CD1915A, 0x67D39FA3,
				0x05532AA9}}, { {0x5E189E8E, 0x4E581C88, 0x0F20C18E, 0xB5D60EF5,
				0x8A663059, 0xEEE0E8FA, 0x3C7A3164, 0x00F62F99}, {0xE521EAAB,
				0xC2F983CD, 0xC0C3385B, 0x025B1039, 0xCC5CF7F0, 0x75EDD3E0, 0x179B42CE,
				0x063EBD7B}}, 0}, { { {0x4918E724, 0x985876B3, 0x4BF791E2,
				0xE3932EBC, 0x2E409D4D, 0xFCCA328A, 0x506CF6E3, 0x1BD94F42}, {
				0x4C4A4AE9, 0x2F88D920, 0x3973BE63, 0x17ED23FB, 0x1E0057DF, 0x7E84F65E,
				0x7A859C95, 0x101DFAD0}}, { {0xB3A78C05, 0x4495B8AC, 0xAA8FD8E0,
				0x08496A0F, 0xDB7F2191, 0x70AA745B, 0xDEBDBFFF, 0x1C4B8C14}, {
				0xDC02D561, 0x42549462, 0x094EEB40, 0x343C8D6D, 0x2A3941C1, 0x465BDD20,
				0xA0EC0ABD, 0x1AC785C7}}, 0}};
#endif
#elif (BNCURVE == BN158)
#ifdef MONTGOMERY_ARITHMETIC
const bbkem_public BB1_PUBLIC = { { { 0x628292D8, 0xF16AA502, 0xCA5604F0,
		0x7AB2DF31, 0x2009001D }, { 0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD,
		0x34A37CB4, 0x03F81FE6 }, 0 }, { { 0x54F66120, 0x87EC6219, 0x6D8D5E74,
		0xE479644B, 0x06DDDB3C }, { 0x1ECB4E47, 0x0831D5F9, 0x69D78097,
		0xFC13C702, 0x0DCA0A9E }, 0 }, { { 0x4766376C, 0x64104DAB, 0x7DC87065,
		0x7AFB056B, 0x0B6E4EDE }, { 0xF01000B7, 0xE85BE00E, 0x192ADA99,
		0x59E00726, 0x00823935 }, 0 }, { { { { 0xEB9F9ADD, 0x7B54E725,
		0x31513590, 0x82C9CF25, 0x11FA46DE }, { 0xBF504934, 0xC24472F5,
		0xE682A5B6, 0xD1792D0A, 0x0B25ED5D } }, { { 0x6D1653BE, 0xF6DF99FF,
		0x0BCC62E1, 0xB8E7092C, 0x01C1D0DD }, { 0x71DA2BB6, 0xEE942B93,
		0x8382C112, 0xA00FE1C8, 0x1B8A4AA2 } } }, { { { 0xDA67E36E, 0xC53BEDBA,
		0xF5EFCD88, 0x5D702D66, 0x10833FAB }, { 0xA07906B7, 0x2A9F5F6C,
		0xE9954F76, 0x54607732, 0x1E2A8473 } }, { { 0xC25AD029, 0xF13C99FC,
		0xBD1CE771, 0x61683B1F, 0x06B218AB }, { 0xAE0CB63C, 0x816E7B73,
		0x36926959, 0xC61DAD75, 0x04734C62 } } }, { { { 0x6AD04A48, 0x7F7C1D2A,
		0x4D881129, 0x76E2EF2D, 0x00DD2E05 }, { 0xDD5E4D7E, 0x04F4B6CB,
		0xE95AF0E6, 0x23F15A7B, 0x067774CD } }, { { 0xA6F70F79, 0x24F6DA6E,
		0x70540C75, 0x7ADE2C27, 0x0C35C6B5 }, { 0x23A008B2, 0x03605C0F,
		0xC636F2D5, 0x1C4CBA1D, 0x1B12CEC4 } } } } };

const bbkem_pk BB1_PK = { { { { 0xEB167900, 0xB01FA560, 0xA0757B48, 0x8362E403,
		0x188C8A20 }, { 0x09F41D63, 0x81FB42D2, 0x684073E7, 0xE5FEE7C5,
		0x15E2A9C1 } }, { { 0xDB581443, 0x3AD9AD75, 0xDC88C59E, 0xA79A8CB0,
		0x172772B0 }, { 0x264614E2, 0x0C903295, 0x3A29F1CF, 0x2324BC73,
		0x08BC1B1E } }, 0 }, { { { 0x0F8A4F3B, 0xF9A3311A, 0x794CEB41,
		0x3259D614, 0x221F60AC }, { 0xBF7D6C48, 0xCC4CADF3, 0xC905B569,
		0x923F905B, 0x0EBC3461 } }, { { 0xEA8C0431, 0xDD3BCB00, 0xA6D62CDA,
		0xA070B451, 0x0166719F }, { 0x9640BE71, 0x804940EA, 0xEB165593,
		0x0C416C93, 0x1A65FF2D } }, 0 } };
#endif
#endif
