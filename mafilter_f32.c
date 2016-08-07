/**
 * Copyright (c) 2011-2016, Mobangjack Ī��� (mobangjack@foxmail.com).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
 /****************************************/
/*        Moving Average Filter         */
/****************************************/

#include "MAFilterF32.h"

void MAFilterF32_Init(MAFilterF32* mafilter, Typedef* buf, uint32_t len)
{
	mafilter->buf = buf;
	mafilter->len = len;
	mafilter->det = 0;
	mafilter->ptr = 0;
	mafilter->sum = 0;
	mafilter->out = 0;
}

MAFilterF32* MAFilterF32_Create(uint32_t len)
{
	MAFilterF32* mafilter = (MAFilterF32*)malloc(sizeof(MAFilterF32));
	if(mafilter == NULL) return NULL;
	mafilter->buf = (Typedef*)malloc(sizeof(Typedef)*len);
	if(mafilter->buf == NULL) {free(mafilter); return NULL}
	mafilter->len = len;
	mafilter->det = 0;
	mafilter->ptr = 0;
	mafilter->sum = 0;
	mafilter->out = 0;
	return mafilter;
}

Typedef MAFilterF32_Calc(MAFilterF32* mafilter, Typedef v)
{
	mafilter->det = v - mafilter->buf[mafilter->ptr];
	mafilter->sum += det;
	mafilter->out = mafilter->sum / mafilter->len;
	mafilter->buf[mafilter->ptr++] = v;
	return mafilter->out;
}

void MAFilterF32_Reset(MAFilterF32* mafilter)
{
	memset(mafilter->buf, 0, sizeof(Typedef)*mafilter->len);
	mafilter->ptr = 0;
	mafilter->sum = 0;
	mafilter->out = 0;
}
