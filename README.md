# Islandora Export Extra

## Introduction

Generates a block with metadata export options that can be embedded in any object page. Currently supported export formats include:

* BibTex
* EndNote
* MARC
* MARCXML
* MODS
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

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

Citeproc is a 3rd party code dependency, typically managed by Composer. If you're already using Islandora Scholar you've probably already set this up, but if you haven't you'll get an error like this:

```
Error: Class 'Seboettg\CiteProc\CiteProc' not found in citeproc_get_citeproc_php_instance() (line 119 of /var/www/html/sites/all/modules/islandora/islandora_scholar/modules/citeproc/citeproc.module).
```

To fix you should follow the main Islandora Scholar install [dependency installation instructions](https://github.com/islandora/islandora_scholar/#requirements). Typically this means:

* `cd` into the `sites/all/modules/islandora/islandora_scholar/modules/citeproc` folder and run `composer install`

## Configuration

Enable the module via Administration » Modules (admin/modules). Using `admin/structure/block`, place the "Islandora Metadata Export" block in the desired region (a sidebar typically works well). Then click "configure" to expose the following options:

* Give the block an optional title
* Enable any of the available export formats: BibTex, EndNote, MARC, MARCXML, MODS, DublinCore, RIS, JSON
* In the "Pages" visibility section you can use wildcards to include/exclude paths from including the block. The default is "only show on: `islandora/object/*`"
* In the "Roles" visibility section you can include/exclude certain Drupal user roles from seeing the block.

Note: Users need to have permission to view MODs and RDF data streams to download.   

## Troubleshooting/Issues

Having problems or solved a problem? Check out the Islandora google groups for a solution.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

## Maintainers/Sponsors

Current maintainers:

* Hertzel Armengol <emudojo@gmail.com>
* Born-Digital <hello@born-digital.com>

## Development

If you would like to contribute to this module, please check out our helpful [Documentation for Developers](https://github.com/Islandora/islandora/wiki#wiki-documentation-for-developers) info, as well as our [Developers](http://islandora.ca/developers) section on the Islandora.ca site.

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
