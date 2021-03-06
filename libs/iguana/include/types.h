/*
 * Copyright (c) 2004, National ICT Australia
 */
/*
 * Copyright (c) 2007 Open Kernel Labs, Inc. (Copyright Holder).
 * All rights reserved.
 *
 * 1. Redistribution and use of OKL4 (Software) in source and binary
 * forms, with or without modification, are permitted provided that the
 * following conditions are met:
 *
 *     (a) Redistributions of source code must retain this clause 1
 *         (including paragraphs (a), (b) and (c)), clause 2 and clause 3
 *         (Licence Terms) and the above copyright notice.
 *
 *     (b) Redistributions in binary form must reproduce the above
 *         copyright notice and the Licence Terms in the documentation and/or
 *         other materials provided with the distribution.
 *
 *     (c) Redistributions in any form must be accompanied by information on
 *         how to obtain complete source code for:
 *        (i) the Software; and
 *        (ii) all accompanying software that uses (or is intended to
 *        use) the Software whether directly or indirectly.  Such source
 *        code must:
 *        (iii) either be included in the distribution or be available
 *        for no more than the cost of distribution plus a nominal fee;
 *        and
 *        (iv) be licensed by each relevant holder of copyright under
 *        either the Licence Terms (with an appropriate copyright notice)
 *        or the terms of a licence which is approved by the Open Source
 *        Initative.  For an executable file, "complete source code"
 *        means the source code for all modules it contains and includes
 *        associated build and other files reasonably required to produce
 *        the executable.
 *
 * 2. THIS SOFTWARE IS PROVIDED ``AS IS'' AND, TO THE EXTENT PERMITTED BY
 * LAW, ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE, OR NON-INFRINGEMENT, ARE DISCLAIMED.  WHERE ANY WARRANTY IS
 * IMPLIED AND IS PREVENTED BY LAW FROM BEING DISCLAIMED THEN TO THE
 * EXTENT PERMISSIBLE BY LAW: (A) THE WARRANTY IS READ DOWN IN FAVOUR OF
 * THE COPYRIGHT HOLDER (AND, IN THE CASE OF A PARTICIPANT, THAT
 * PARTICIPANT) AND (B) ANY LIMITATIONS PERMITTED BY LAW (INCLUDING AS TO
 * THE EXTENT OF THE WARRANTY AND THE REMEDIES AVAILABLE IN THE EVENT OF
 * BREACH) ARE DEEMED PART OF THIS LICENCE IN A FORM MOST FAVOURABLE TO
 * THE COPYRIGHT HOLDER (AND, IN THE CASE OF A PARTICIPANT, THAT
 * PARTICIPANT). IN THE LICENCE TERMS, "PARTICIPANT" INCLUDES EVERY
 * PERSON WHO HAS CONTRIBUTED TO THE SOFTWARE OR WHO HAS BEEN INVOLVED IN
 * THE DISTRIBUTION OR DISSEMINATION OF THE SOFTWARE.
 *
 * 3. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR ANY OTHER PARTICIPANT BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _IGUANA_TYPES_H_
#define _IGUANA_TYPES_H_

#include <l4/types.h>
#include <stdint.h>
#include <stddef.h>

typedef uintptr_t objref_t;
typedef objref_t memsection_ref_t;
typedef objref_t thread_ref_t;
typedef objref_t pd_ref_t;
#if defined(CONFIG_SESSION)
typedef objref_t session_ref_t;
#endif
typedef objref_t eas_ref_t;
typedef objref_t hw_ref_t;
typedef objref_t quota_ref_t;
typedef objref_t physpool_ref_t;
typedef objref_t physmem_ref_t;
typedef objref_t virtpool_ref_t;
typedef objref_t clist_ref_t;
typedef objref_t zone_ref_t;

typedef struct {
    union {
        objref_t obj;
        memsection_ref_t memsection;
        thread_ref_t thread;
        pd_ref_t pd;
#if defined(CONFIG_SESSION)
        session_ref_t session;
#endif
        eas_ref_t eas;
        hw_ref_t hw;
        quota_ref_t quota;
        physpool_ref_t physpool;
        physmem_ref_t physmem;
        virtpool_ref_t virtpool;
        clist_ref_t clist;
        zone_ref_t zone;
    } ref;
    uintptr_t passwd;
} cap_t;

#define INVALID_ADDR ((uintptr_t)(~0UL))
#define INVALID_CAP {{ INVALID_ADDR }}
#define IS_VALID_CAP(x) ((x).ref.obj != INVALID_ADDR)

/*
 * A structure that holds the sizes of various Iguana internal data
 * structures.  These values are used to calculate the values in the
 * the document 'L4/Iguana Memory Usage'.
 */
typedef struct iguana_stats 
{
    size_t eas_size;

    size_t ms_size;
    size_t pte_size;
    size_t active_pd_size;
    size_t objtable_page_size;
    size_t objtable_order;
    size_t objtable_entry_size;
    size_t physmem_list_size;

    size_t physmem_size;
    size_t physmem_mem_size;

    size_t virtmem_size;
    size_t virtmem_mem_size;

    size_t pool_size;
    size_t pool_mem_size;

    size_t pd_size;
    size_t active_ms_size;
    size_t clist_node_size;
    size_t cb_buffer_handle_size;

//#if defined(CONFIG_SESSION)
    size_t session_size;
    size_t session_node_size;
//#endif
    size_t thread_size;
} iguana_stats_t;

#endif /* _IGUANA_TYPES_H_ */
