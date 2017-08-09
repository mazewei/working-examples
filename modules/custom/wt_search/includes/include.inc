<?php

/**
 * handle all search parameters and build query in solr search
 *  @author Matthias Weinhold <m.weinhold@module-7.com>
 *  @category search services
 *  @copyright (c) 2016, module7, Kavalierstraße 19, 13187 Berlin
 *  @license GPL
 */
class JournalSearchService {
    
    const SEARCH_LIMIT = 20;
    
    public static function simpleSearch($parameter) {
        $parameter = 'Berlin';
        
        $server = search_api_server_load('solr_bdi');
        $index = search_api_index_load('alle_hefte');
        $query = new SearchApiQuery($index);
        
        $query->sort('field_erscheinungsdatum', 'DESC');
        
        $result = $query->execute();
        $current_page = pager_default_initialize($result['result count'], self::SEARCH_LIMIT);
        $chunks = array_chunk($result['results'], self::SEARCH_LIMIT, TRUE);

        $result['results'] = $chunks[$current_page];
        return $result;
        
    }
    
}
