#
#   Copyright 2004-2016, by the California Institute of Technology.
#   ALL RIGHTS RESERVED. United States Government Sponsorship
#   acknowledged. Any commercial use must be negotiated with the Office
#   of Technology Transfer at the California Institute of Technology.
#
#   This software may be subject to U.S. export control laws and
#   regulations.  By accepting this document, the user agrees to comply
#   with all U.S. export laws and regulations.  User has the
#   responsibility to obtain export licenses, or other export authority
#   as may be required before exporting such information to foreign
#   countries or providing access to foreign persons.
#

from __future__ import print_function

import os

from genmsg import MsgGenerationException

#from . name import *

## :param type_name outdir: Full path to output directory
## :returns int: status. 0 if successful
def write_modmk(outdir): #, msg_types, srv_types):
    if not os.path.isdir(outdir):
        #TODO: warn?
        return 0

    xml_in_dir = set([f for f in os.listdir(outdir)
                      if f.endswith('.xml')])
    _write_modmk(outdir, sorted(xml_in_dir))

# TODO(mereweth) if we want to independently specify the generated XML files
#     generated_xml = [_msg_serializable_xml_name(f) for f in sorted(msg_types)]
#     generated_xml.extend([_port_xml_name(f) for f in sorted(msg_types)]
#     write_msg_modmk(outdir, generated_xml)

#     generated_xml = [_srv_serializable_xml_name(f) for f in sorted(srv_types)]
#     generated_xml.extend([_port_xml_name(f) for f in sorted(srv_types)]
#     write_msg_modmk(outdir, generated_xml)

    return 0

def _write_modmk(outdir, generated_xml):
    if not os.path.exists(outdir):
        os.makedirs(outdir)
    elif not os.path.isdir(outdir):
        raise MsgGenerationException("file preventing the creating of Fprime directory: %s"%dir)
    p = os.path.join(outdir, 'mod.mk')
    with open(p, 'w') as f:
        f.write('SRC = \\\n')
        if len(generated_xml) != 0:
            for xml in generated_xml[:-1]:
                f.write('%s \\\n'%xml)
            f.write('%s\n'%generated_xml[-1])
    return 0
