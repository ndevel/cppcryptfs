/*
cppcryptfs : user-mode cryptographic virtual overlay filesystem.

Copyright (C) 2016-2021 Bailey Brown (github.com/bailey27/cppcryptfs)

cppcryptfs is based on the design of gocryptfs (github.com/rfjakob/gocryptfs)

The MIT License (MIT)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "stdafx.h"
#include "CryptSetting.h"
#include "CryptSettings.h"


void CryptCheckBoxSetting::Set(SetType set_type, bool save)
{
	bool val = false;

	switch (set_type) {
	case SetType::Current:
		GetSettingCurrent(m_key, val);
		break;
	case SetType::Default:
		GetSettingDefault(m_key, val);
		break;
	case SetType::Recommended:
		GetSettingRecommended(m_key, val);
		break;
	case SetType::Changed:
		GetSettingCurrent(m_key, val);
		val = !val;
		break;
	}
	
	m_dlg.CheckDlgButton(m_id, val ? 1 : 0);

	if (save)
		SaveSetting(m_key, val);
	
}




void CryptComboBoxSetting::Set(SetType set_type, bool save)
{
}