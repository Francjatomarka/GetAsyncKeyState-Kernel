unsigned __int16 GetKey(unsigned int a1)
	{
		__int16 result;

		if (a1 >= 0x100) { result = 0; }
		else
		{
			unsigned __int64 v1 = (unsigned __int8)a1;
			unsigned __int64 v2 = (unsigned __int64)(unsigned __int8)a1 >> 3;

			__int16 v4 = 0;
			unsigned int v3 = v1 & 7;

			int v5 = *(unsigned __int8*)(v2 + EPtr(gafAsyncKeyStateRecentDown));

			if (_bittest((LONG*)&v5, v3)) {
				v4 = 1;
				*(UCHAR*)(v2 + EPtr(gafAsyncKeyStateRecentDown)) = v5 & ~(1 << v3);
			}

			result = v4 | 0x8000;
			if (!(*((UCHAR*)EPtr(gafAsyncKeyState) + (v1 >> 2)) & (unsigned __int8)(1 << (2 * (v1 & 3)))))
				result = v4;
		}

		return result;
	}
