/*****************************************************************************

        DcKiller.h
        Copyright (c) 2006 Laurent de Soras

--- Legal stuff ---

This file is part of AY2Wav.

AY2Wav is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

AY2Wav is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with AY2Wav; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*Tab=3***********************************************************************/



#if ! defined (DcKiller_HEADER_INCLUDED)
#define	DcKiller_HEADER_INCLUDED

#if defined (_MSC_VER)
	#pragma once
	#pragma warning (4 : 4250) // "Inherits via dominance."
#endif



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



class DcKiller
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:

						DcKiller ();
	virtual			~DcKiller () {}

	void				set_sample_freq (float sample_freq);
	void				set_cutoff_freq (float f_0);

	void				clear_buffers ();
	void				process_block (float data_ptr [], long nbr_spl);



/*\\\ PROTECTED \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

protected:



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:

	void				update_eq ();

	float				_sample_freq;
	float				_cutoff_freq;
	float				_coef_x [2];
	float				_coef_y;
	float				_mem_x;
	float				_mem_y;
	float				_anti_denormal;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:

						DcKiller (const DcKiller &other);
	DcKiller &		operator = (const DcKiller &other);
	bool				operator == (const DcKiller &other);
	bool				operator != (const DcKiller &other);

};	// class DcKiller



//#include	"DcKiller.hpp"



#endif	// DcKiller_HEADER_INCLUDED



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
