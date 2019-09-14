# Islandora Export Extra

## Introduction

Generates a block with metadata export options that can be embedded in any object page. Currently supported export formats include:

* BibTex
* EndNote
* MARC
* MARCXML
* DublinCore
* RIS

## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)
* [Islandora Scholar](https://github.com/islandora/islandora_scholar)
* [Islandora Google Scholar](https://github.com/Born-Digital-US/islandora_scholar/tree/7.x/modules/islandora_google_scholar)
* [Islandora Solr](https://github.com/Islandora/islandora_solr_search)
* [Citeproc](https://github.com/Islandora/islandora_scholar/tree/7.x/modules/citeproc)
* [CSL](https://github.com/Islandora/islandora_scholar/tree/7.x/modules/csl)
* [Bibutils](https://github.com/Islandora/islandora_scholar/tree/7.x/modules/bibutils)

## Installation

Run <pre>composer install</pre> at the root of the folder to install the required libraries.

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration

Enable the module via Administration » Modules (admin/modules). Place the block on the desired pages, and enable the formats that users can export to from the block configuration page. Users need to have permission to view MODs and RDF data streams to download.   

## Troubleshooting/Issues

Having problems or solved a problem? Check out the Islandora google groups for a solution.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

## Maintainers/Sponsors

Current maintainers:

* Hertzel Armengol <emudojo@gmail.com>

## Development

If you would like to contribute to this module, please check out our helpful [Documentation for Developers](https://github.com/Islandora/islandora/wiki#wiki-documentation-for-developers) info, as well as our [Developers](http://islandora.ca/developers) section on the Islandora.ca site.

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
