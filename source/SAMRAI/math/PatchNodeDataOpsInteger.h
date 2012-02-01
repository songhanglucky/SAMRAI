/*************************************************************************
 *
 * This file is part of the SAMRAI distribution.  For full copyright
 * information, see COPYRIGHT and COPYING.LESSER.
 *
 * Copyright:     (c) 1997-2011 Lawrence Livermore National Security, LLC
 * Description:   Operations for integer node-centered patch data.
 *
 ************************************************************************/

#ifndef included_math_PatchNodeDataOpsInteger
#define included_math_PatchNodeDataOpsInteger

#include "SAMRAI/SAMRAI_config.h"

#include "SAMRAI/pdat/NodeData.h"
#include "SAMRAI/math/PatchNodeDataBasicOps.h"
#include "SAMRAI/math/ArrayDataNormOpsInteger.h"
#include "SAMRAI/hier/Box.h"
#include "SAMRAI/hier/Patch.h"
#include "SAMRAI/tbox/PIO.h"

#include <boost/shared_ptr.hpp>
#include <iostream>

namespace SAMRAI {
namespace math {

/**
 * Class PatchNodeDataOpsInteger provides a collection of operations
 * that may be used to manipulate integer node-centered patch data.  The
 * operations include basic arithmetic, min, max, etc.  With the assertion
 * of a few basic routines, this class inherits its interface (and
 * thus its functionality) from the base class PatchNodeDataBasicOps
 * from which it is derived.
 *
 * A more extensive set of operations is implemented for real (double and
 * float) and complex patch data in the classes PatchNodeDataOpsReal
 * and PatchNodeDataOpsComplex, repsectively.
 *
 * @see math::PatchNodeDataBasicOps
 */

class PatchNodeDataOpsInteger:
   public PatchNodeDataBasicOps<int>
{
public:
   /**
    * Empty constructor and destructor.
    */
   PatchNodeDataOpsInteger();

   virtual ~PatchNodeDataOpsInteger();

   /**
    * Return the number of data values for the node-centered data object
    * in the given box.  Note that it is assumed that the box refers to
    * the cell-centered index space corresponding to the patch hierarchy.
    */
   int
   numberOfEntries(
      const boost::shared_ptr<pdat::NodeData<int> >& data,
      const hier::Box& box) const;

   /**
    * Copy dst data to src data over given box.
    */
   void
   copyData(
      boost::shared_ptr<pdat::NodeData<int> >& dst,
      const boost::shared_ptr<pdat::NodeData<int> >& src,
      const hier::Box& box) const;

   /**
    * Swap pointers for patch data objects.  Objects are checked for
    * consistency of depth, box, and ghost box.
    */
   void
   swapData(
      boost::shared_ptr<hier::Patch> patch,
      const int data1_id,
      const int data2_id) const;

   /**
    * Print data entries over given box to given output stream.
    */
   void
   printData(
      const boost::shared_ptr<pdat::NodeData<int> >& data,
      const hier::Box& box,
      std::ostream& s = tbox::plog) const;

   /**
    * Initialize data to given scalar over given box.
    */
   void
   setToScalar(
      boost::shared_ptr<pdat::NodeData<int> >& dst,
      const int& alpha,
      const hier::Box& box) const;

   /**
    * Set destination component to absolute value of source component.
    * That is, each destination entry is set to \f$d_i = \| s_i \|\f$.
    */
   void
   abs(
      boost::shared_ptr<pdat::NodeData<int> >& dst,
      const boost::shared_ptr<pdat::NodeData<int> >& src,
      const hier::Box& box) const;

private:
   // The following are not implemented:
   PatchNodeDataOpsInteger(
      const PatchNodeDataOpsInteger&);
   void
   operator = (
      const PatchNodeDataOpsInteger&);

   ArrayDataNormOpsInteger d_array_ops;

};

}
}
#endif
