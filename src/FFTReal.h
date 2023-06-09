/*****************************************************************************

        FFTReal.h
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



#if ! defined (FFTReal_HEADER_INCLUDED)
#define	FFTReal_HEADER_INCLUDED

#if defined (_MSC_VER)
	#pragma once
	#pragma warning (4 : 4250) // "Inherits via dominance."
#endif



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include	"def.h"
#include	"DynArray.h"
#include	"OscSinCos.h"



template <class DT>
class FFTReal
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:

	enum {			MAX_BIT_DEPTH	= 30	};	// So length can be represented as long int

	typedef	DT	DataType;

	explicit			FFTReal (long length);
	virtual			~FFTReal () {}

	long				get_length () const;
	void				do_fft (DataType f [], const DataType x []) const;
	void				do_ifft (const DataType f [], DataType x []) const;
	void				rescale (DataType x []) const;
	DataType *		use_buffer () const;



/*\\\ PROTECTED \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

protected:



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:

   // Over this bit depth, we use direct calculation for sin/cos
   enum {	      TRIGO_BD_LIMIT	= 12  };

	typedef	OscSinCos <DataType>	OscType;

	void				init_br_lut ();
	void				init_trigo_lut ();
	void				init_trigo_osc ();

	FORCEINLINE const long *
						get_br_ptr () const;
	FORCEINLINE const DataType	*
						get_trigo_ptr (int level) const;
	FORCEINLINE long
						get_trigo_level_index (int level) const;

	inline void		compute_fft_general (DataType f [], const DataType x []) const;
	inline void		compute_direct_pass_1_2 (DataType df [], const DataType x []) const;
	inline void		compute_direct_pass_3 (DataType df [], const DataType sf []) const;
	inline void		compute_direct_pass_n (DataType df [], const DataType sf [], int pass) const;
	inline void		compute_direct_pass_n_lut (DataType df [], const DataType sf [], int pass) const;
	inline void		compute_direct_pass_n_osc (DataType df [], const DataType sf [], int pass) const;

	inline void		compute_ifft_general (const DataType f [], DataType x []) const;
	inline void		compute_inverse_pass_n (DataType df [], const DataType sf [], int pass) const;
	inline void		compute_inverse_pass_n_osc (DataType df [], const DataType sf [], int pass) const;
	inline void		compute_inverse_pass_n_lut (DataType df [], const DataType sf [], int pass) const;
	inline void		compute_inverse_pass_3 (DataType df [], const DataType sf []) const;
	inline void		compute_inverse_pass_1_2 (DataType x [], const DataType sf []) const;

	const long		_length;
	const int		_nbr_bits;
	DynArray <long>
						_br_lut;
	DynArray <DataType>
						_trigo_lut;
	mutable DynArray <DataType>
						_buffer;
   mutable DynArray <OscType>
						_trigo_osc;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:

						FFTReal ();
						FFTReal (const FFTReal &other);
	FFTReal &		operator = (const FFTReal &other);
	bool				operator == (const FFTReal &other);
	bool				operator != (const FFTReal &other);

};	// class FFTReal



#include	"FFTReal.hpp"



#endif	// FFTReal_HEADER_INCLUDED



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
