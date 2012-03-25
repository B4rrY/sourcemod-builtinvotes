/**
 * vim: set ts=4 :
 * =============================================================================
 * Builtin Votes
 * Copyright (C) 2011 Ross Bemrose (Powerlord).  All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 *
 * Version: $Id$
 */

#ifndef _INCLUDE_BUILTINVOTESTYLE_L4D2_H
#define _INCLUDE_BUILTINVOTESTYLE_L4D2_H

#include "BuiltinVoteStyle_L4D_Base.h"

// These are swapped from the order they appear in L4D/L4D2
#define L4D2_VOTE_YES_INDEX								1
#define L4D2_VOTE_NO_INDEX								0

class CL4D2BuiltinVote;

class L4D2BuiltinVoteStyle : public L4DBaseBuiltinVoteStyle
{
public:
	L4D2BuiltinVoteStyle();
public: // L4DBaseBuiltinVoteStyle
	//void SendDisplay(int clients[], unsigned int num_clients, IBaseBuiltinVote *vote) =0;
	bool CheckVoteType(BuiltinVoteType type);
	const char *GetStyleName();
	IBaseBuiltinVote *CreateVote(IBuiltinVoteHandler *handler, BuiltinVoteType type, IdentityToken_t *pOwner=NULL);
	unsigned int GetApproxMemUsage();
};

class CL4D2BuiltinVote : public CL4DBaseBuiltinVote
{
public:
	CL4D2BuiltinVote(IBuiltinVoteHandler *pHandler, IBuiltinVoteStyle *pStyle, BuiltinVoteType type, IdentityToken_t *pOwner);
	~CL4D2BuiltinVote();
public: //IBaseBuiltinVote
	bool Display(int clients[], unsigned int num_clients);
	unsigned int GetApproxMemUsage();
public: // CBaseBuiltinVote
	void Cancel_Finally();
	void DisplayVotePass(const char *winner);
	void DisplayVotePass(const char *translation, const char *winner="");
	void DisplayVoteFail(BuiltinVoteFailReason reason=BuiltinVoteFail_Generic);
	void DisplayVoteFail(int client, BuiltinVoteFailReason reason=BuiltinVoteFail_Generic);
	//void DisplayCallVoteFail(int client, BuiltinCallVoteFailReason reason, short param1);
	void ClientSelectedItem(int client, unsigned int item);
protected:
	void InternalDisplayVoteFail(int clients[], unsigned int num_clients, BuiltinVoteFailReason reason=BuiltinVoteFail_Generic);

};

extern L4D2BuiltinVoteStyle g_L4D2BuiltinVoteStyle;
extern ICvar *icvar;

#endif // _INCLUDE_BUILTINVOTESTYLE_L4D2_H